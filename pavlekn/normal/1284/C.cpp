#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 335;

int f[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (f[i - 1] * i) % m;
    }
    for (int i = 1; i <= n; ++i)
    {
        int cur = (f[i] * f[n - i]) % m;
        cur *= (n - i + 1);
        cur %= m;
        cur *= (n - i + 1);
        cur %= m;
        ans += cur;
        ans %= m;
    }
    cout << ans << endl;
    return 0;
}