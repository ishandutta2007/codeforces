#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

vector<int> ans;

int dp0[MAXN];
int dp1[MAXN];
int dp2[MAXN];

int deg[MAXN];
int used[MAXN][3];

vector<vector<int>> g(MAXN);

void dfs(int u, int num)
{
    if (used[u][num])
    {
        return;
    }
    used[u][num] = true;
    if (num == 0)
    {
        ans.push_back(u);
    }
    for (auto v : g[u])
    {
        if (num == 0)
        {
            if (dp0[v] == min(dp2[v], min(dp1[v], dp0[v])))
            {
                dfs(v, 0);
            }
            else if (dp1[v] == min(dp2[v], min(dp1[v], dp0[v])))
            {
                dfs(v, 1);
            }
            else
            {
                dfs(v, 2);
            }
        }
        if (num == 1)
        {
            dfs(v, 0);
        }
        if (num == 2)
        {
            if (dp0[v] == min(dp0[v], dp1[v]))
            {
                dfs(v, 0);
            }
            else
            {
                dfs(v, 1);
            }
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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; ++i)
        {
            used[i][0] = false;
            used[i][1] = false;
            used[i][2] = false;
        }
        for (int i = 0; i <= n; ++i)
        {
            g[i] = {};
            deg[i] = 0;
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            u = n + 1 - u;
            v = n + 1 - v;
            g[v].push_back(u);
            ++deg[u];
        }
        for (int i = 1; i <= n; ++i)
        {
            if (deg[i] == 0)
            {
                g[0].push_back(i);
            }
        }
        for (int i = n; i >= 0; --i)
        {
            dp0[i] = 1;
            dp1[i] = 0;
            dp2[i] = 0;
            for (auto v : g[i])
            {
                dp0[i] += min(dp2[v], min(dp1[v], dp0[v]));
                dp1[i] += dp0[v];
                dp2[i] += min(dp0[v], dp1[v]);
            }
        }
        ans = {};
        dfs(0, 0);
        unordered_set<int> ss;
        for (int i = 1; i < ans.size(); ++i)
        {
            ss.insert(ans[i]);
        }
        cout << ss.size() << "\n";
        for (auto el : ss)
        {
            cout << n + 1 - el << " ";
        }
        cout << "\n";
    }
    return 0;
}