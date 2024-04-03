#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* createDynamicArray(size_t capacity) {
    DynamicArray *dynArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (dynArray == NULL) {
        perror("Failed to allocate memory for dynamic array");
        exit(EXIT_FAILURE);
    }

    dynArray->array = (int*)malloc(capacity * sizeof(int));
    if (dynArray->array == NULL) {
        perror("Failed to allocate memory for array");
        free(dynArray);
        exit(EXIT_FAILURE);
    }

    dynArray->size = 0;
    dynArray->capacity = capacity;
    return dynArray;
}

void resizeDynamicArray(DynamicArray *dynArray) {
    size_t newCapacity = dynArray->capacity * 2;
    int *newArray = (int*)realloc(dynArray->array, newCapacity * sizeof(int));
    if (newArray == NULL) {
        perror("Failed to reallocate memory for array");
        exit(EXIT_FAILURE);
    }

    dynArray->array = newArray;
    dynArray->capacity = newCapacity;
}

void appendDynamicArray(DynamicArray *dynArray, int value) {
    if (dynArray->size >= dynArray->capacity) {
        resizeDynamicArray(dynArray);
    }

    dynArray->array[dynArray->size++] = value;
}

void freeDynamicArray(DynamicArray *dynArray) {
    free(dynArray->array);
    free(dynArray);
}

int main() {
    DynamicArray *myArray = createDynamicArray(5);

    // Adding elements to the dynamic array
    
    appendDynamicArray(myArray, 10);
    appendDynamicArray(myArray, 20);
    appendDynamicArray(myArray, 30);
    appendDynamicArray(myArray, 40);
    appendDynamicArray(myArray, 50);

    // Printing the elements 
    for (size_t i = 0; i < myArray->size; i++) {
        printf("%d ", myArray->array[i]);
    }
    printf("\n");

    // Freeing memory allocated for the dynamic array
    freeDynamicArray(myArray);

    return 0;
}
