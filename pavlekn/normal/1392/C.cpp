#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 11;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        int cur = 0;
        for (int i = n - 1; i > 0; --i)
        {
            cur = max(0ll, a[i - 1] - a[i]);
            ans += cur;
        }
        cout << ans << endl;
    }
    return 0;
}