#include <cstdio>

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

int main() {
    int n = ni();
    int m = ni();
    int ans = n;
    if (ans > m) ans = m;
    printf("%d\n", ans + 1);
    for (int i = 0; i <= n && i <= m; i++) {
        printf("%d %d\n", n - i, i);
    }
}