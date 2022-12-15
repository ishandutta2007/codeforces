#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 2e5 + 5;

int a[Nmax];
int dp[Nmax];

signed main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += (i % 2 == 0) * a[i];
        }
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0) dp[i] = dp[i - 1];
            if (i % 2) dp[i] += a[i];
            else dp[i] -= a[i];
        }
        int odd = 0, even = 1e18, add = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                add = max(add, dp[i] - odd);
                odd = min(odd, dp[i]);
            } else {
                add = max(add, dp[i] - even);
                even = min(even, dp[i]);
            }
        }
        cout << ans + add << "\n";
    }
    return 0;
}