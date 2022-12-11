#include<bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("-O3")
#pragma GCC target("avx")

const int MAXN = 1e6 + 7;

vector<vector<int>> g(MAXN);
vector<vector<int>> h(MAXN);
int used[MAXN];
int used2[MAXN];

vector<int> ts;
vector<int> ans;

void dfs(int u)
{
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
    ts.push_back(u);
}

int cmp = 0;

void dfs2(int u)
{
    if (!cmp)
    {
        ans.push_back(u);
    }
    used2[u] = true;
    for (auto v : h[u])
    {
        if (!used2[v])
        {
            dfs2(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m;
        cin >> n >> m;
        ts = {};
        ans = {};
        for (int i = 0; i < n; ++i)
        {
            used[i] = false;
            used2[i] = false;
            g[i] = {};
            h[i] = {};
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            h[v].push_back(u);
        }
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                dfs(i);
            }
        }
        cmp = 0;
        reverse(ts.begin(), ts.end());
        for (auto el : ts)
        {
            if (!used2[el])
            {
                dfs2(el);
                ++cmp;
            }
        }
        vector<int> was(n);
        for (auto el : ans)
        {
            was[el] = true;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if (!was[i])
            {
                res.push_back(i);
            }
        }
        if (cmp <= 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            cout << res.size() << " " << ans.size() << endl;
            for (auto el : res)
            {
                cout << el + 1 << " ";
            }
            cout << endl;
            for (auto el : ans)
            {
                cout << el + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}