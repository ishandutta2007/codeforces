#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
const int MOD = 998244353;
int fac[MAXN + 1];
int invFac[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int n, int r)
{
    int ans = (int) ((long long) fac[n] * invFac[r] % MOD);
    return (int) ((long long) ans * invFac[n - r] % MOD);
}

int main()
{
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invFac[i] = modinv(fac[i]);
    }
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = n / i;
        if (num < k)
            break;
        ans += choose(num - 1, k - 1);
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}