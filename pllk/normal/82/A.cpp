#include <stdio.h>

int t[5] = {1,1,1,1,1};
int n;

int main(void) {
    scanf("%i", &n);
    int k = 0;
    while (1) {
        n -= t[k];
        t[k] *= 2;
        if (n <= 0) break;
        k = (k+1)%5;
    }
    if (k == 0) printf("Sheldon");
    if (k == 1) printf("Leonard");
    if (k == 2) printf("Penny");
    if (k == 3) printf("Rajesh");
    if (k == 4) printf("Howard");
    printf("\n");
}