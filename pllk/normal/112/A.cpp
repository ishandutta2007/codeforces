#include <stdio.h>
#include <string.h>

char a[100+1], b[100+1];

int main(void) {
    scanf("%s %s", a, b);
    for (int i = 0; a[i]; i++) if (a[i] > 'Z') a[i] -= ('a'-'A');
    for (int i = 0; b[i]; i++) if (b[i] > 'Z') b[i] -= ('a'-'A');
    int t = strcmp(a, b);
    if (t < 0) t = -1;
    if (t > 0) t = 1;
    printf("%i\n", t);
}