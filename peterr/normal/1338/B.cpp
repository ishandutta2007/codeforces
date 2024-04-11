#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int level[MAXN + 1];

void dfs(int root, int p, int l)
{
    level[root] = l;
    for (int adj : adjList[root])
    {
        if (adj == p)
            continue;
        dfs(adj, root, l + 1);
    }
}

int solve(int root, int p)
{
    int ans = 0;
    bool foundLeaf = false;
    for (int adj : adjList[root])
    {
        if (adj == p)
            continue;
        if ((int) adjList[adj].size() == 1)
        {
            foundLeaf = true;
        }
        else
        {
            ans++;
            ans += solve(adj, root);
        }
    }
    ans += foundLeaf;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int root = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        if ((int) adjList[a].size() > 1)
            root = a;
        else if ((int) adjList[b].size() > 1)
            root = b;
    }
    dfs(root, root, 0);
    int ans1 = 1;
    int par = -1;
    for (int i = 1; i <= n; i++)
    {
        if ((int) adjList[i].size() == 1)
        {
            if (par == -1)
                par = level[i] % 2;
            else
            {
                if (level[i] % 2 != par)
                    ans1 = 3;
            }
        }
    }
    int ans2 = solve(root, root);
    cout << ans1 << " " << ans2 << "\n";

    return 0;
}