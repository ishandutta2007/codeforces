//By Qingyu
#include <bits/stdc++.h>

inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    int res = 0, ch = nc();
    while(!isdigit(ch)) ch = nc();
    while(isdigit(ch)) res = res * 10 + ch - 48, ch = nc();
    return res;
}

int main() {
    int n = read(), k = read();
    int range = (k << 1) + 1;
    printf("%d\n", (int)ceil(n * 1.0 / range));
    int init = k + 1;
    if (n % range < k + 1 && (n % range)) init = n % range;
    for (int i = init; i <= n; i += (k << 1) + 1)
        printf("%d ", i);
    return 0;
}