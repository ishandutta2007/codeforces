#include <stdio.h>

char s[100+1];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        char m = s[i];
        if (m <= 'Z') m += ('a'-'A');
        if (m == 'a' || m == 'o' || m == 'y' ||
            m == 'e' || m == 'u' || m == 'i') continue;
        printf(".%c", m);
    }
    printf("\n");
}