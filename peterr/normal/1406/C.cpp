#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int s[MAXN + 1];
int par[MAXN + 1];

void dfs(int v, int p)
{
    s[v] = 1;
    par[v] = p;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        s[v] += s[adj];
    }
}

int dfs2(int v, int p)
{
    par[v] = p;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        return dfs2(adj, v);
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vector<pair<int, int>> ans;
        if (n & 1)
        {
            ans.push_back(make_pair(1, adjList[1][0]));
            ans.push_back(make_pair(1, adjList[1][0]));
        }
        else
        {
            dfs(1, 1);
            int v = 1;
            while (v <= n && s[v] != n / 2)
            {
                v++;
            }
            if (v > n)
            {
                ans.push_back(make_pair(1, adjList[1][0]));
                ans.push_back(make_pair(1, adjList[1][0]));
            }
            else
            {
                int leaf = dfs2(par[v], v);
                ans.push_back(make_pair(leaf, par[leaf]));
                ans.push_back(make_pair(leaf, v));
            }
        }
        for (pair<int, int> pr : ans)
        {
            cout << pr.first << " " << pr.second << "\n";
        }
    }
    return 0;
}