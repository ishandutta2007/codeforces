#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
int fac[MAXN + 1];
int invFac[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) (((long long) ans * b) % MOD);
        e >>= 1;
        b = (int) (((long long) b * b) % MOD);
    }
    return ans;
}

int inv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int n, int r)
{
    int ans = (int) (((long long) fac[n] * invFac[r]) % MOD);
    return (int) (((long long) ans * invFac[n - r]) % MOD);
}

int main()
{
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) (((long long) fac[i - 1] * i) % MOD);
        invFac[i] = inv(fac[i]);
    }
    int n;
    long long k;
    cin >> n >> k;
    if (k >= n)
    {
        cout << 0 << endl;
        return 0;
    }
    if (k == 0)
    {
        cout << fac[n] << endl;
        return 0;
    }
    int r = n - k;
    int ans = modpow(r, n);
    int sgn = -1;
    for (int i = 1; i < r; i++)
    {
        int temp = (int) (((long long) choose(r, i) * modpow(r - i, n)) % MOD);
        if (sgn == -1)
            ans = (ans - temp + MOD) % MOD;
        else
            ans = (ans + temp) % MOD;
        sgn *= -1;
    }
    ans = (int) (((long long) ans * choose(n, r)) % MOD);
    cout << (int) (((long long) 2 * ans) % MOD) << endl;
    return 0;
}