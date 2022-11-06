#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 1E9 + 7;
int fac[MAXN + 1];
int invFac[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        e >>= 1;
        b = (int) ((long long) b * b % MOD);
    }
    return ans;
}

int inv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

int main()
{
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invFac[i] = inv(fac[i]);
    }
    string s;
    cin >> s;
    int n = (int) s.length();
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
            r++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
            r--;
        if (s[i] == '(' && r)
        {
            ans += choose(r + l, r - 1);
            if (ans >= MOD)
                ans -= MOD;
        }
        if (s[i] == '(')
            l++;
    }
    cout << ans << "\n";
    return 0;
}