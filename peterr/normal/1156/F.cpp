#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 5000;
int a[MAXN];
int freq[MAXN + 1];
int inv[MAXN + 1];
int fac[MAXN + 1];
int invFac[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

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

int getInv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            add(dp[i][j], (int) ((long long) freq[i] * dp[i - 1][j - 1] % MOD));
        }
    }
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        inv[i] = getInv(i);
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invFac[i] = (int) ((long long) invFac[i - 1] * inv[i] % MOD);
    }
    int ans = 0;
    int ptr = 1;
    int uq = 0;
    while (ptr <= n)
    {
        if (!freq[ptr])
        {
            ptr++;
            continue;
        }
        if (freq[ptr] == 1)
        {
            ptr++;
            uq++;
            continue;
        }
        for (int i = 0; i <= uq; i++)
        {
            int temp = (int) ((long long) invFac[n] * fac[n - i - 2] % MOD);
            int ways = dp[ptr - 1][i];
            ways = (int) ((long long) ways * freq[ptr] % MOD);
            ways = (int) ((long long) ways * (freq[ptr] - 1) % MOD);
            temp = (int) ((long long) temp * ways % MOD);
            add(ans, temp);
        }
        uq++;
        ptr++;
    }
    cout << ans << "\n";
    return 0;
}