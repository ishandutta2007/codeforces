#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<int> b(n);
        int mx = 0;
        int cnt = -1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i] >> b[i];
            mx = max(mx, a[i]);
            cnt = max(cnt, a[i] - b[i]);
        }
        int ans = 1;
        x -= mx;
        if (x > 0 && cnt <= 0)
        {
            cout << -1 << endl;
            continue;
        }
        x = max(x, 0ll);
        if (x == 0)
        {
            cout << ans << endl;
            continue;
        }
        ans += (x - 1 + cnt) / cnt;
        cout << ans << endl;
    }
    return 0;
}