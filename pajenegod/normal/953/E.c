#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int main() {

    int k;
    scanf("%i", &k);
    int* numbers = calloc(k,sizeof(int));
    int* next = calloc(k,sizeof(int));
    int* prev = calloc(k,sizeof(int));

    for (int i=0; i<k; ++i)
    {
        scanf("%i",&numbers[i]);
        next[i] = i+1;
        prev[i] = i-1;
    }
    next[k-1] = -1;
    int j = 0;
    while (next[j]!=-1)
    {
        if (numbers[j] == numbers[next[j]])
        {
            numbers[j] += 1;
            if (next[next[j]]!=-1)
                prev[next[next[j]]]=j;
            next[j] = next[next[j]]; 

            if (prev[j]!=-1)
                j = prev[j];
        }else{
            j = next[j];
        }
    
    }
    int count = 1;
    j=0;
    while (next[j]!=-1)
    {
        j = next[j];
        count += 1;
    }       
    printf( "%i\n",count );
    j = 0;
    printf("%i",numbers[j]);
    while (next[j]!=-1)
    {
        j = next[j];
        printf(" %i",numbers[j]);
        //cout << " " << numbers[j];
    }
}