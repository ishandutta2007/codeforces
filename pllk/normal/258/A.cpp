#include <stdio.h>

char s[100000+1];

int main(void) {
    scanf("%s", s);
    int k = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') {
            k = i;
            break;
        }
    }
    for (int i = 0; i < k; i++) printf("%c", s[i]);
    for (int i = k+1; s[i]; i++) printf("%c", s[i]);
    printf("\n");
}