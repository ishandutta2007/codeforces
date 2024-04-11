#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

const int MAXN = 2e5 + 77;

int f[MAXN];

int pow(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return a;
    }
    int ans = pow(a, n / 2);
    ans *= ans;
    ans %= mod;
    if (n % 2)
    {
        ans *= a;
    }
    return ans % mod;
}

int C(int k, int n)
{
    return ((f[n] * pow(f[k], mod - 2) % mod) * pow(f[n - k], mod - 2)) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k >= n)
    {
        cout << 0 << endl;
        return 0;
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (f[i - 1] * i) % mod;
    }
    int ans = C(k, n);
    if (k)
    {
        ans *= 2;
    }
    int t = 1;
    int d = 0;
    for (int i = n - k; i > 0; --i)
    {
        d += pow(i, n) * t * C(i, n - k);
        d %= mod;
        t = -t;
    }
    ans *= d;
    ans %= mod;
    ans += mod;
    cout << ans % mod << endl;
    return 0;
}