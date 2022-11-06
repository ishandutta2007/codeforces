#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
int sz[MAXN + 1][2];
vector<int> adjList[MAXN + 1];
int val[MAXN + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
}

void reroot(int x, int y)
{
    sz[x][0] -= sz[y][1];
    sz[x][1] -= sz[y][0];
    sz[y][0] += sz[x][1];
    sz[y][1] += sz[x][0];
}

int solve(int v, int p)
{
    int ans = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        reroot(v, adj);
        add(ans, solve(adj, v));
        reroot(adj, v);
    }
    int temp = 0;
    add(temp, (int) ((long long) val[v] * (sz[v][0] - 1) % MOD));
    for (int i = 1; i >= 0; i--)
    {
        int sum = 0;
        for (int adj : adjList[v])
        {
            int curSize = sz[adj][i];
            int ways = (int) ((long long) curSize * sum % MOD);
            add(temp, (int) ((long long) ways * val[v] % MOD));
            sum += curSize;
        }
        val[v] = -val[v];
    }
    add(temp, temp);
    add(ans, temp);
    return ans;
}

void dfs(int v, int p)
{
    sz[v][0] = 1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        sz[v][0] += sz[adj][1];
        sz[v][1] += sz[adj][0];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        add(ans, val[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 1);
    add(ans, solve(1, 1));
    cout << ans << "\n";
    return 0;
}