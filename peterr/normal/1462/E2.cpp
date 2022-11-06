#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
int a[MAXN];
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

int choose(int n, int k)
{
    if (k > n)
        return 0;
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invFac[i] = modinv(fac[i]);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        sort(a, a + n);
        int right = 0;
        for (int i = 0; i < n; i++)
        {
            while (right + 1 < n && a[right + 1] - a[i] <= k)
                right++;
            int num = right - i;
            ans += choose(num, m - 1);
            if (ans >= MOD)
                ans -= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}