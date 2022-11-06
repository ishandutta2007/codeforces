#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int values[MAXN + 1];
vector<int> adjList[MAXN + 1];
long long treeVal[MAXN + 1];

void calcTrees(int v, int p)
{
    treeVal[v] = values[v];
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            calcTrees(adj, v);
            treeVal[v] += treeVal[adj];
        }
    }
}

long long solve(int v, int p, int dist)
{
    long long ans = (long long) values[v] * dist;
    for (int adj : adjList[v])
    {
        if (adj != p)
            ans += solve(adj, v, dist + 1);
    }
    return ans;
}

long long solve4Real(int v, int p, long long sum)
{
    long long ans = sum;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        ans = max(ans, sum + treeVal[1] - 2 * treeVal[adj]);
        ans = max(ans, solve4Real(adj, v, sum + treeVal[1] - 2 * treeVal[adj]));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> values[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    calcTrees(1, 0);
    /*
    cout << "test tree val" << endl;
    for (int i = 1; i <= n; i++)
        cout << treeVal[i] << " " << endl;
    */
    long long sum = solve(1, 0, 0);
    cout << solve4Real(1, 0, sum);
    return 0;
}