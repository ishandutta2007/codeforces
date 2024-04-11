#include <stdio.h>
#include <string.h>

int n;
char s[100+1];

int main(void) {
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int p = strlen(s);
        if (p <= 10) printf("%s\n", s);
        else printf("%c%i%c\n", s[0], p-2, s[p-1]);
    }
}