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
        vector<int> deg(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ans += a[i];
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u; --v;
            ++deg[u]; ++deg[v];
        }
        set<pair<int, int>> s;
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < deg[i] - 1; ++j)
            {
                s.insert({-a[i], num++});
            }
        }
        cout << ans << " ";
        for (int i = 0; i < n - 2; ++i)
        {
            ans -= s.begin()->first;
            cout << ans << " ";
            s.erase(s.begin());
        }
        cout << endl;
    }
    return 0;
}