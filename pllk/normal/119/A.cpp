#include <stdio.h>

int a, b, n;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main(void) {
    scanf("%i %i %i", &a, &b, &n);
    while (1) {
        n -= gcd(n, a);
        if (n < 0) {
            printf("1\n");
            break;
        }
        n -= gcd(n, b);
        if (n < 0) {
            printf("0\n");
            break;
        }
    }
}