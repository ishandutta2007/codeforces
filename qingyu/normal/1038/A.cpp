#include <bits/stdc++.h>

char data[100005];

inline int nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

int alp[5000];

inline int read() {
    int res = 0, ch = nc();
    while (!isdigit(ch)) ch = nc();
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = nc();
    return res;
}

int main() {
    int n, k;
    scanf("%d%d%s", &n, &k, data);
    for (int i = 0; i < n; ++i)
        alp[data[i] - 'A']++;
    int ans = 2147483645;
    for (int i = 0; i < k; ++i)
        ans = std::min(ans, alp[i]);
    printf("%d", ans * k);
    return 0;
}

//By Qingyu