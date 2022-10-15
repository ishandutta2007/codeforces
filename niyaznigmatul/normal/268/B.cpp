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
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (n - i - 1) * (i + 1) + 1;
    }
    printf("%I64d\n", ans);
}