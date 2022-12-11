#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;

vector<vector<int>> g(MAXN);

int used[MAXN];

int dist[MAXN];

void dfs(int u, int d=0)
{
    used[u] = true;
    dist[u] = d;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v, d + 1);
        }
    }
}

void clear()
{
    for (int i = 0; i < n; ++i)
    {
        used[i] = false;
    }
}

int get()
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] > dist[ans])
        {
            ans = i;
        }
    }
    return ans;
}

int p[MAXN];

void dfs2(int u, int pr=-1)
{
    used[u] = true;
    p[u] = pr;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs2(v, u);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    int u = get();
    clear();
    dfs(u);
    u = get();
    clear();
    dfs(u);
    int v = get();
    sm += dist[v];
    vector<int> t;
    t.push_back(u);
    t.push_back(v);
    clear();
    p[u] = -1;
    dfs2(u);
    deque<int> q;
    vector<int> dst(n, -1);
    while (v != -1)
    {
        q.push_back(v);
        dst[v] = 0;
        v = p[v];
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (auto v : g[u])
        {
            if (dst[v] == -1)
            {
                dst[v] = dst[u] + 1;
                q.push_back(v);
            }
        }
    }
    for (auto el : t)
    {
        dst[el] = -1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dst[i] > dst[ans])
        {
            ans = i;
        }
    }
    sm += dst[ans];
    cout << sm << endl;
    cout << t[0] + 1 << " " << t[1] + 1 << " " << ans + 1 << endl;
    return 0;
}