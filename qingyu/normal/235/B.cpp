#include <bits/stdc++.h>

typedef long double ld;
constexpr int N = 2e6 + 50;
ld E[N], f[N], g[N];
ld p[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%Lf", p + i);
    for (int i = 1; i <= n; ++i)
        f[i] = p[i] * (1 + f[i - 1]),
        E[i] = E[i - 1] + p[i] * (2 * f[i - 1] + 1);
    printf("%.10Lf", E[n]);
    return 0;
}