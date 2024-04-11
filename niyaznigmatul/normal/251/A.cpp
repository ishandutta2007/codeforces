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

int a[123456];

int main() {
    int n = ni();
    int d = ni();
    for (int i = 0; i < n; i++) {
        a[i] = ni();        
    }
    long long ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= d) {
            ++j;
        }
        long long m = j - i - 2;
        ans += m * (m + 1) / 2;
    }
    printf("%I64d\n", ans);
}