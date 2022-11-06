#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E15;
const int LOGN = 16;
const int MAXN = 1E5;
vector<pair<int, int>> adjList[MAXN + 1];
int level[MAXN + 1];
bool sp[MAXN + 1];
int anc[LOGN + 1][MAXN + 1];
long long treeDist[MAXN + 1];
vector<vector<long long>> dist;
bool visited[MAXN + 1];

void dijkstra(int v)
{
    fill(visited + 1, visited + MAXN + 1, false);
    vector<long long> d(MAXN + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0LL, v));
    while (!pq.empty())
    {
        pair<long long, int> pr = pq.top();
        pq.pop();
        if (visited[pr.second])
            continue;
        visited[pr.second] = true;
        d[pr.second] = pr.first;
        for (pair<int, int> edge : adjList[pr.second])
        {
            int adj = edge.first;
            int w = edge.second;
            if (!visited[adj] && pr.first + w < d[adj])
            {
                d[adj] = pr.first + w;
                pq.push(make_pair(pr.first + w, adj));
            }
        }
    }
    dist.push_back(d);
}

int lca(int v, int u)
{
    if (level[v] > level[u])
        swap(u, v);
    int diff = level[u] - level[v];
    for (int i = LOGN; i >= 0; i--)
    {
        if (diff & (1 << i))
        {
            u = anc[i][u];
        }
    }
    for (int i = LOGN; i >= 0; i--)
    {
        if (anc[i][v] != anc[i][u])
        {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    if (u != v)
        return anc[0][u];
    return u;
}

void dfs(int v, int p, int l)
{
    anc[0][v] = p;
    level[v] = l;
    for (pair<int, int> pr : adjList[v])
    {
        int adj = pr.first;
        int w = pr.second;
        if (adj == p)
            continue;
        if (level[adj] == -1)
        {
            treeDist[adj] = treeDist[v] + w;
            dfs(adj, v, l + 1);
        }
        else
        {
            sp[v] = sp[adj] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adjList[u].push_back(make_pair(v, d));
        adjList[v].push_back(make_pair(u, d));
    }
    fill(level + 1, level + n + 1, -1);
    dfs(1, 1, 0);
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    for (int i = 1; i <= n; i++)
        if (sp[i])
            dijkstra(i);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        long long ans = treeDist[u] + treeDist[v] - 2 * treeDist[lca(u, v)];
        for (int i = 0; i < (int) dist.size(); i++)
        {
            ans = min(ans, dist[i][u] + dist[i][v]);
        }
        cout << ans << "\n";
    }
    return 0;
}