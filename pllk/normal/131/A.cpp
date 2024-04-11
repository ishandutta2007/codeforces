#include <stdio.h>

char s[100+1];

int main(void) {
    scanf("%s", &s);
    int v = 0;
    for (int i = 1; s[i]; i++) {
        if (s[i] > 'Z') v = 1;
    }
    if (v) {
        printf("%s\n", s);
    } else {
        if (s[0] > 'Z') printf("%c", s[0]-('a'-'A'));
        else printf("%c", s[0]+('a'-'A'));
        for (int i = 1; s[i]; i++) {
            printf("%c", s[i]+('a'-'A'));
        }
        printf("\n");
    }
}