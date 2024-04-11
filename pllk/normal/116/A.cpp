#include <stdio.h>

int n;
int a, k;
int m;

int main(void) {
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%i", &a);
        k -= a;
        scanf("%i", &a);
        k += a;
        if (k > m) m = k;
    }
    printf("%i\n", m);
}