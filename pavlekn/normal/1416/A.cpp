#include <bits/stdc++.h>

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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n + 2, n);
        vector<vector<int>> pos(n);
        for (int i = 0; i < n; ++i)
        {
            pos[i].push_back(-1);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
            pos[a[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i)
        {
            pos[i].push_back(n);
        }
        for (int i = 0; i < n; ++i)
        {
            int mx = 0;
            for (int j = 1; j < pos[i].size(); ++j)
            {
                mx = max(mx, pos[i][j] - pos[i][j - 1]);
            }
            ans[mx] = min(ans[mx], i);
        }
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = min(ans[i], ans[i - 1]);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i] == n)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << ans[i] + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}