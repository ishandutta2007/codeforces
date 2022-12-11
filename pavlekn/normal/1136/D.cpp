#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> deg(n + 1);
    vector<int> a(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (pos[u] < pos[v])
        {
            ++deg[u];
            g[v].push_back(u);
        }
    }
    int ans = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        int u = a[i];
        if (deg[u] == n - 1 - i - ans)
        {
            ++ans;
            for (auto v : g[u])
            {
                --deg[v];
            }
        }
    }
    cout << ans << endl;
    return 0;
}