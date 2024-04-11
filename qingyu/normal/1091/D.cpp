#include <bits/stdc++.h>

typedef long long LL;
constexpr int N = 1e6;
constexpr int mod = 998244353;

LL fact[N], f[N];
int main()
{
    int n;
    scanf("%d", &n);
    fact[0] = 1;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = i * fact[i - 1] % mod;
        f[i] = (f[i - 1] + fact[i - 1] - 1 + mod) * i % mod;
    }
    printf("%lld", f[n]);
    return 0;
}