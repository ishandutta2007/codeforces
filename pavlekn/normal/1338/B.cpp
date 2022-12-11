#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 75;

vector<vector<int>> g(MAXN);

int used[MAXN];

int fl = false;

void dfs(int u, int d)
{
    used[u] = true;
    if (d % 2 && g[u].size() == 1)
    {
        fl = true;
    }
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v, d + 1);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    set<int> s;
    int u = 0;
    for (int i = 0; i < n; ++i)
    {
        if (g[i].size() == 1)
        {
            u = i;
            ++cnt;
            s.insert(g[i][0]);
        }
    }
    dfs(u, 0);
    int ans1 = 1;
    int ans2 = s.size() + (n - 1 - cnt);
    if (fl)
    {
        ans1 = 3;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}