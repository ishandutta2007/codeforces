#include <stdio.h>

int main(void) {
    int n, k, a, b, t = 0;
    scanf("%i %i", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%i", &a);
        if (a == 0) break;
        if (i <= k) t++;
        if (i == k) b = a;
        if (i > k && a == b) t++;
    }
    printf("%i\n", t);
}