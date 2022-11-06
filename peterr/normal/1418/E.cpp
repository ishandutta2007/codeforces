#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
int a[MAXN + 1];
long long pref[MAXN + 2];
long long suf[MAXN + 2];

int modpow(int b, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
            ans = (int) ((long long) ans * b % MOD);
        p >>= 1;
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
        pref[i] %= MOD;
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = a[i] + suf[i + 1];
        suf[i] %= MOD;
    }
    while (m--)
    {
        int dur, def;
        cin >> dur >> def;
        int ind = 0;
        for (int jump = n / 2 + 1; jump > 0; jump >>= 1)
        {
            while (ind + jump <= n && a[ind + jump] < def)
            {
                ind += jump;
            }
        }
        ind++;
        int big = n - ind + 1;
        int temp = (int) ((long long) (big + 1 - min(dur, big + 1)) * modinv(big + 1) % MOD);
        temp = (int) ((long long) temp * pref[ind - 1] % MOD);
        int ans = temp;
        temp = (int) ((long long) (big - min(dur, big)) * modinv(big) % MOD);
        temp = (int) ((long long) temp * suf[ind] % MOD);
        ans += temp;
        if (ans >= MOD)
            ans -= MOD;
        cout << ans << "\n";
    }
    return 0;
}