#include <iostream>

inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    int res = 0;
    char ch = 0;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

int main() {
    int t = read();
    while (t--) {
        int x = read(), ans = 0;
        do if(x & 1) ++ans; while(x >>= 1, x);
        printf("%d\n", 1 << ans);
    }
    return 0;
}