#include <bits/stdc++.h>

inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline long long read() {
    long long res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

int main() {
    int T = read();
    while (T--) {
        long long L = read(), R = read();
        printf("%lld %lld\n", L, L << 1);
    } 
    return 0;
}