#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;

inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
    int res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

int A[N];

int main()
{
    int n = read();
    for (int i = 0; i < n; ++i) A[i] = read();
    std::sort(A, A + n);
    int t = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] >= t)
        {
            t += A[i];
            ++ans;
        }
    }
    printf("%d", ans);
    return 0;
}