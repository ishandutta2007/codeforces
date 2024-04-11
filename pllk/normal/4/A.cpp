#include <stdio.h>

int main(void) {
    int n;
    scanf("%i", &n);
    if (n%2 == 0 && n != 2) printf("YES\n");
    else printf("NO\n");
}