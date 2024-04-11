#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
vector<tuple<int, int, int>> adjList[MAXN + 1];
tuple<int, int, int> edges[MAXN];
int ans[MAXN];

bool dfs(int v, int p, int target, int bt, int &minW)
{
    if (v == target)
        return true;
    for (int i = 0; i < (int) adjList[v].size(); i++)
    {
        tuple<int, int, int> e = adjList[v][i];
        int u = get<0>(e);
        int ind = get<2>(e);
        int w = ans[ind];
        if (u != p)
        {
            if (dfs(u, v, target, bt, minW))
            {
                minW = min(minW, w);
                adjList[v][i] = make_tuple(u, max(bt, w), ind);
                ans[ind] = max(bt, w);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(make_tuple(b, 0, i));
        adjList[b].push_back(make_tuple(a, 0, i));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, g;
        cin >> a >> b >> g;
        edges[i] = make_tuple(g, a, b);
    }
    sort(edges, edges + m);
    bool valid = true;
    for (int i = m - 1; i >= 0; i--)
    {
        int a, b, g;
        g = get<0>(edges[i]);
        a = get<1>(edges[i]);
        b = get<2>(edges[i]);
        int minn = 2E6;
        dfs(a, a, b, g, minn);
        if (minn > g)
            valid = false;
    }
    if (valid)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (i > 0)
                cout << " ";
            cout << (ans[i] == 0 ? 1 : ans[i]);
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}