#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 3E5;
int twopow[MAXN + 1];
int halfpow[MAXN + 1];
int dp[MAXN + 1];
int power[MAXN + 1];
int pref[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
        {
            ans = (int) ((long long) ans * b % MOD);
        }
        e >>= 1;
        b = (int) ((long long) b * b % MOD);
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int twoinv = modinv(2);
    twopow[0] = halfpow[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        twopow[i] = (int) ((long long) twopow[i - 1] * 2 % MOD);
        halfpow[i] = (int) ((long long) halfpow[i - 1] * twoinv % MOD);
    }
    for (int i = 0; i + 1 <= MAXN; i += 2)
    {
        power[i] = MAXN - i;
        power[i + 1] = MAXN - i;
    }
    int n;
    cin >> n;
    dp[0] = halfpow[power[0]];
    dp[1] = (int) ((long long) halfpow[power[1]] * halfpow[1] % MOD);
    pref[0] = dp[0];
    pref[1] = dp[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = pref[i - 1];
        int diff = power[i - 1] - 1;
        dp[i] = (int) ((long long) dp[i] * twopow[diff] % MOD);
        dp[i] = (int) ((long long) dp[i] * halfpow[power[i]] % MOD);
        pref[i] = pref[i - 2] + dp[i];
        if (pref[i] >= MOD)
            pref[i] -= MOD;
    }
    cout << (int) ((long long) dp[n] * twopow[power[n]] % MOD) << "\n";
    return 0;
}