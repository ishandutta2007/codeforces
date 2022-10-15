#include <cstdio>
#include <algorithm>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        sg = 1;
        c = getchar();
    }   
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;
}

char s[1123];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int it = 0; it < k; it++) {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                char t = s[i];
                s[i] = s[i + 1];
                s[i + 1] = t;
                i++;
            }
        }
    }
    puts(s);
}