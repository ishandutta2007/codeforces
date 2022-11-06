#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 998244353;
int p[MAXN];

int modinv(int x)
{
    int ans = 1;
    int sq = x;
    for (int i = 0; i <= 30; i++)
    {
        if ((MOD - 2) & (1 << i))
        {
            ans = (int) (((long long) ans * sq) % MOD);
        }
        sq = (int) (((long long) sq * sq) % MOD);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int hundred = modinv(100);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i] = (int) (((long long) p[i] * hundred) % MOD);
        p[i] = modinv(p[i]);
    }
    int ans = 0;
    int cur = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        cur = (int) (((long long) cur * p[i]) % MOD);
        ans = (ans + cur) % MOD;
    }
    cout << ans << endl;
    return 0;
}