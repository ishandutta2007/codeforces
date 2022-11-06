#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
int fac[MAXN + 1];
int invFac[MAXN + 1];

int modInv(int x)
{
    int k = MOD - 2;
    int ans = 1;
    while (k)
    {
        if (k & 1)
        {
            ans = (int) (((long long) ans * x) % MOD);
        }
        k >>= 1;
        x = (int) (((long long) x * x) % MOD);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) (((long long) fac[i - 1] * i) % MOD);
        invFac[i] = modInv(fac[i]);
    }
    int temp = 0;
    for (int i = n - 1; i <= m; i++)
    {
        int t = (int) (((long long) fac[i - 1] * invFac[i - n + 1]) % MOD);
        temp += t;
        if (temp >= MOD)
            temp -= MOD;
    }
    int ans = 0;
    for (int l = 1; n - l - 1 >= 1; l++)
    {
        int r = n - l - 1;
        int t = (int) (((long long) temp * invFac[l - 1]) % MOD);
        t = (int) (((long long) t * invFac[r - 1]) % MOD);
        ans += t;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << endl;
    return 0;
}