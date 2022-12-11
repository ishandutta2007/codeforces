#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int used[MAXN];
int sz[MAXN];

int n;
int ans1, ans2;

vector<vector<pair<int, int>>> g(MAXN);

void dfs(int u)
{
    sz[u] = 1;
    used[u] = true;
    for (auto p : g[u])
    {
        int v = p.first;
        int w = p.second;
        if (!used[v])
        {
            dfs(v);
            sz[u] += sz[v];
            if (sz[v] % 2 == 0)
            {
                ans1 -= w;
            }
            ans2 += w * min(sz[v], n - sz[v]);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int k;
        cin >> k;
        n = 2 * k;
        ans1 = 0;
        ans2 = 0;
        for (int i = 0; i < 2 * k; ++i)
        {
            g[i] = {};
            used[i] = false;
        }
        for (int i = 0; i < 2 * k - 1; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            ans1 += w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(0);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}