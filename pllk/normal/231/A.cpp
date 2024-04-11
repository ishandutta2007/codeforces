#include <stdio.h>

int n;
int a, b, c;

int main(void) {
    scanf("%i", &n);
    int t = 0;
    for (int i = 0; i < n; i++) {
        scanf("%i %i %i", &a, &b, &c);
        if (a+b+c >= 2) t++;
    }
    printf("%i\n", t);
}