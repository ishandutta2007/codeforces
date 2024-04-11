#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i + 1];
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i)
        {
            ans += abs(a[i] - a[i + 1]);
        }
        for (int i = 1; i <= n; ++i)
        {
            int x = max(0LL, min(a[i] - a[i - 1], a[i] - a[i + 1]));
            ans -= x;
        }
        cout << ans << endl;
    }
    return 0;
}