#include <cstdio>
#include <cstring>

char s[102];

int main () {
    gets(s);
    int n = strlen(s);

    int kecil = -1;
    for (int i=0; i<n; i++) if (s[i] >= 'a' && s[i] <= 'z') kecil = i;

    if (kecil > 0) puts(s);
    else {
        if (kecil == 0) printf("%c", s[0] - 'a' + 'A');
        else printf("%c", s[0] - 'A' + 'a');

        for (int i=1; i<n; i++) printf("%c", s[i] - 'A' + 'a');
        printf("\n");
    }
    return 0;
}