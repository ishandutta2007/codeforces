#include <cstdio>
#include <memory.h>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;

}

long long nl() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    long long ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;
}



const int bits = 41;
long long a[123456];
int link[2][123456 * (bits + 5)];
int fr;

void add(long long x) {
    int v = 0;
    for (int i = 0; i < bits; i++) {
        int bit = (x >> (bits - i - 1)) & 1;
        if (link[bit][v] < 0) link[bit][v] = fr++;
        v = link[bit][v];
    }
}

long long get(long long x) {
    int v = 0;
    long long ans = 0;
    for (int i = 0; i < bits; i++) {
        int bit = (x >> (bits - i - 1)) & 1;
        if (link[bit ^ 1][v] >= 0) {
            ans ^= 1LL << (bits - i - 1);
            v = link[bit ^ 1][v];
        } else {
            v = link[bit][v];
        }
    }
    return ans;
}

int main() {
    memset(link, -1, sizeof link);
    fr = 1;
    int n = ni();
    long long xo = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] = nl();
        xo ^= a[i];
        if (xo > ans) ans = xo;
    }
    long long xo2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        xo2 ^= a[i];
        if (xo2 > ans) ans = xo2;
    }
    xo2 = 0;
    add(0LL);
    for (int i = n - 1; i >= 0; i--) {
        long long ff = get(xo);
        if (ans < ff) ans = ff;
        xo ^= a[i];
        xo2 ^= a[i];
        add(xo2);
    }
    printf("%I64d\n", ans);
}