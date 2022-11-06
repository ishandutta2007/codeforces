#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int dep[MAXN + 1];
int par[MAXN + 1];
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
vector<int> ans;

void dfs(int v, int p, int d)
{
    dep[v] = d;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v, d + 1);
    }
}

int dfs2(int v, int p, int k, int len)
{
    int total = 1;
    ans.push_back(v);
    int save = -1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (visited[adj])
            save = adj;
        else
        {
            if (k - total > len)
            {
                int num = dfs2(adj, v, k - total, len);
                total += num;
                ans.push_back(v);
            }
        }
    }
    if (k - total && save != -1)
    {
        int num = dfs2(save, v, k - total, len - 1);
        total += num;
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        int n, k;
        cin >> n >> k;
        fill(visited + 1, visited + n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int p;
            cin >> p;
            adjList[i + 2].push_back(p);
            adjList[p].push_back(i + 2);
            par[i + 2] = p;
        }
        dfs(1, 1, 0);
        int deepest = max_element(dep + 1, dep + n + 1) - dep;
        int maxDepth = dep[deepest];
        while (1)
        {
            visited[deepest] = true;
            if (deepest == 1)
                break;
            deepest = par[deepest];
        }
        dfs2(1, 1, k, maxDepth);
        cout << ans.size() - 1 << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}