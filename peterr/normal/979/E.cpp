#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
const int MOD = 1E9 + 7;
int dp[MAXN + 1][2][MAXN + 1][MAXN + 1][MAXN + 1];
int c[MAXN + 1];
int twopow[MAXN + 1];
int fac[MAXN + 1];
int invFac[MAXN + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

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

int choose(int n, int k)
{
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

int chooseSum(int n, int k)
{
    int ans = 0;
    while (k <= n)
    {
        ans += choose(n, k);
        if (ans >= MOD)
            ans -= MOD;
        k += 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    twopow[0] = 1;
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        twopow[i] = (int) ((long long) twopow[i - 1] * 2 % MOD);
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invFac[i] = modinv(fac[i]);
    }
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dp[0][0][0][0][0] = 1;
    for (int len = 1; len <= n; len++)
    {
        for (int par = 0; par < 2; par++)
        {
            for (int ew = 0; ew <= len; ew++)
            {
                for (int ow = 0; ow + ew <= len; ow++)
                {
                    for (int eb = 0; eb + ow + ew <= len; eb++)
                    {
                        int ob = len - ew - ow - eb;
                        if (ew && c[len] != 0)
                        {
                            int val = dp[len - 1][par][ew - 1][ow][eb];
                            val = (int) ((long long) val * twopow[eb] % MOD);
                            val = (int) ((long long) val * twopow[ow] % MOD);
                            val = (int) ((long long) val * twopow[ew - 1] % MOD);
                            val = (int) ((long long) val * chooseSum(ob, 1) % MOD);
                            add(dp[len][par][ew][ow][eb], val);
                        }
                        if (ow && c[len] != 0)
                        {
                            int val = dp[len - 1][!par][ew][ow - 1][eb];
                            val = (int) ((long long) val * twopow[eb] % MOD);
                            val = (int) ((long long) val * twopow[ow - 1] % MOD);
                            val = (int) ((long long) val * twopow[ew] % MOD);
                            val = (int) ((long long) val * chooseSum(ob, 0) % MOD);
                            add(dp[len][par][ew][ow][eb], val);
                        }
                        if (eb && c[len] != 1)
                        {
                            int val = dp[len - 1][par][ew][ow][eb - 1];
                            val = (int) ((long long) val * twopow[ew] % MOD);
                            val = (int) ((long long) val * twopow[ob] % MOD);
                            val = (int) ((long long) val * twopow[eb - 1] % MOD);
                            val = (int) ((long long) val * chooseSum(ow, 1) % MOD);
                            add(dp[len][par][ew][ow][eb], val);
                        }
                        if (ob && c[len] != 1)
                        {
                            int val = dp[len - 1][!par][ew][ow][eb];
                            val = (int) ((long long) val * twopow[ew] % MOD);
                            val = (int) ((long long) val * twopow[ob - 1] % MOD);
                            val = (int) ((long long) val * twopow[eb] % MOD);
                            val = (int) ((long long) val * chooseSum(ow, 0) % MOD);
                            add(dp[len][par][ew][ow][eb], val);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int ew = 0; ew <= n; ew++)
    {
        for (int ow = 0; ow + ew <= n; ow++)
        {
            for (int eb = 0; eb + ow + ew <= n; eb++)
            {
                add(ans, dp[n][p][ew][ow][eb]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}