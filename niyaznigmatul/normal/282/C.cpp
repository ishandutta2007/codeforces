#include <cstdio>

char s[1234567], t[1234567];

int main() {
    gets(s);
    gets(t);
    int n = 0;
    while (s[n]) n++;
    int m = 0;
    while (t[m]) m++;
    if (n != m) {
        puts("NO");
        return 0;
    }
    int z1 = 1;
    int z2 = 1;
    for (int i = 0; i < n; i++) if (s[i] != '0') z1 = 0;
    for (int i = 0; i < m; i++) if (t[i] != '0') z2 = 0;
    if (z1 != z2) puts("NO"); else puts("YES");
}