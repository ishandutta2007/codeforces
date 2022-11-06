#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E5;
vector<int> p;
vector<int> adjList[MAXN + 1];
vector<long long> edges;
int sz[MAXN + 1];

void dfs(int v, int parent, int n)
{
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj == parent)
            continue;
        dfs(adj, v, n);
        int s = sz[adj];
        sz[v] += s;
        edges.push_back((long long) s * (n - s));
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
        p.clear();
        edges.clear();
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        dfs(1, 1, n);
        sort(edges.begin(), edges.end());
        for (int i = 0; i < (int) edges.size(); i++)
        {
            edges[i] = edges[i] % MOD;
        }
        int m;
        cin >> m;
        for (int i = 0; i < n - 1 - m; i++)
        {
            p.push_back(1);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            p.push_back(x);
        }
        sort(p.begin(), p.end());
        while ((int) p.size() > n - 1)
        {
            int x = p.back();
            p.pop_back();
            int y = p.back();
            p.pop_back();
            p.push_back((int) ((long long) x * y % MOD));
        }
        int ans = 0;
        for (int i = 0; i < (int) p.size(); i++)
        {
            ans += (int) ((long long) edges[i] * p[i] % MOD);
            if (ans >= MOD)
                ans -= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}