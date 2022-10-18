#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

vector<int> col, used1, g[200001], h[200001], d, used, d1;

int dfs(int v, int curV)
{
    used1[v] = curV;
    for (int i = 0; i < h[v].size(); i++)
        if (used1[h[v][i]] == 0 && col[h[v][i]] == col[v])
            dfs(h[v][i], curV);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    col.resize(n + 1);
    used1.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    for (int i = 0; i < n - 1; i++)
    {
        int k, l;
        cin >> k >> l;
        h[k].push_back(l);
        h[l].push_back(k);
    }
    int curV = 1;
    for (int i = 1; i <= n; i++)
        if (used1[i] == 0)
        {
            dfs(i, curV);
            curV++;
        }
    curV--;
    for (int v = 1; v <= n; v++)
        for (int i = 0; i < h[v].size(); i++)
            g[used1[v]].push_back(used1[h[v][i]]);
    int V = 1, h = -1;
    for (int i = 1; i <= curV; i++)
    {
        sort(g[i].begin(), g[i].end());
        int cur = 1;
        for (int j = 1; j < g[i].size(); j++)
            if (g[i][j] != g[i][j - 1] && g[i][j] != i)
                cur++;
        if (cur > h)
        {
            h = cur;
            V = i;
        }
    }
    queue<int> q;
    used.assign(curV + 1, 0);
    d.assign(curV + 1, 1e9);
    q.push(V);
    d[V] = 0;
    used[V] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++)
        {
            int u = g[v][i];
            if (used[u] == 0)
            {
                q.push(u);
                d[u] = d[v] + 1;
                used[u] = 1;
            }
        }
    }
    int dd = -1;
    for (int i = 1; i <= curV; i++)
        if (dd < d[i])
        {
            dd = d[i];
            V = i;
        }
    used.assign(curV + 1, 0);
    d.assign(curV + 1, 1e9);
    q.push(V);
    d[V] = 0;
    used[V] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++)
        {
            int u = g[v][i];
            if (used[u] == 0)
            {
                q.push(u);
                d[u] = d[v] + 1;
                used[u] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= curV; i++)
        if (ans < d[i])
            ans = d[i];
    cout << (ans + 1) / 2;
    return 0;
}