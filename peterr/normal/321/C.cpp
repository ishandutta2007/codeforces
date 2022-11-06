#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int sz[MAXN + 1];
int ans[MAXN + 1];

void dfs(int v, int p)
{
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj != p && ans[adj] == -1)
        {
            dfs(adj, v);
            sz[v] += sz[adj];
        }
    }
}

void solve(int v, int p, int cur)
{
    dfs(v, p);
    int total = sz[v];
    while (true)
    {
        bool found = false;
        for (int adj : adjList[v])
        {
            if (adj != p && ans[adj] == -1 && sz[adj] > total / 2)
            {
                p = v;
                v = adj;
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }
    ans[v] = cur;
    for (int adj : adjList[v])
    {
        if (ans[adj] == -1)
            solve(adj, v, cur + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    fill(ans + 1, ans + n + 1, -1);
    solve(1, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << (char) ('A' + ans[i]);
    }
    cout << endl;
    return 0;
}