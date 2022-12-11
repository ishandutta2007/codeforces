#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int used[MAXN];

vector<vector<int>> g;
vector<int> s(MAXN);
vector<int> a(MAXN, -1);
vector<int> p(MAXN);

int ans = 0;

void dfs(int u)
{
    if (s[u] == -1)
    {
        s[u] = 1e18;
        for (auto v : g[u])
        {
            if (!used[v])
            {
                s[u] = min(s[u], s[v]);
            }
        }
        if (s[u] == 1e18)
        {
            s[u] = s[p[u]];
        }
    }
    if (u != 0)
    {
        a[u] = s[u] - s[p[u]];
        if (a[u] < 0)
        {
            ans = -1e18;
        }
        else
        {
            ans += a[u];
        }
    }
    else
    {
        ans += s[0];
    }
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int v;
        cin >> v;
        --v;
        p[i + 1] = v;
        g[i + 1].push_back(v);
        g[v].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    a[0] = s[0];
    dfs(0);
    if (ans < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}