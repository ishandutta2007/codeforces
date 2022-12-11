#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int, int> dp;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        dp[a[i] - i] += a[i];
        ans = max(ans, dp[a[i] - i]);
    }
    cout << ans << endl;
    return 0;
}