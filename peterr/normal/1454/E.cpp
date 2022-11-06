#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
int sz[MAXN + 1];
long long extra;

int dfs1(int v, int p, int n)
{
    visited[v] = true;
    sz[v] = 1;
    int ret = -1;
    bool backEdge = false;
    bool along = false;
    int where = -1;
    bool base = false;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (visited[adj])
        {
            if (ret != -1)
                continue;
            ret = adj;
            backEdge = true;
            continue;
        }
        int temp = dfs1(adj, v, n);
        sz[v] += sz[adj];
        if (temp != -1)
        {
            ret = temp;
            if (temp == v)
            {
                base = true;
                int num = n - sz[adj];
                extra += (long long) num * (num - 1) / 2;
            }
            else
            {
                where = adj;
                along = true;
            }
        }
    }
    if (backEdge)
    {
        extra += (long long) sz[v] * (sz[v] - 1) / 2;
    }
    if (along)
    {
        int num = sz[v] - sz[where];
        extra += (long long) num * (num - 1) / 2;
    }
    if (base)
        return -1;
    return ret;
}

void dfs2(int v, int p, int root)
{
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj == p || adj == root)
            continue;
        dfs2(adj, v, root);
        sz[v] += sz[adj];
    }
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
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        extra = 0;
        fill(visited + 1, visited + n + 1, false);
        dfs1(1, 1, n);
        long long ans = (long long) n * (n - 1) - extra;
        cout << ans << "\n";
    }
    return 0;
}