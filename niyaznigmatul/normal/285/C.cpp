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

int p[1234567];

int main() {
    int n = ni();
    for (int i = 0; i < n; i++) {
        p[i] = ni();
    }
    std::sort(p, p + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int d = p[i] - (i + 1);
        if (d < 0) d = -d;
        ans += d;
    }
    printf("%I64d\n", ans);
}