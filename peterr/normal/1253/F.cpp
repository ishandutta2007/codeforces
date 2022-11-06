#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int LOGN = 16;
vector<pair<int, int>> adjList[MAXN + 1];
int from[MAXN + 1];
long long dist[MAXN + 1];
bool visited[MAXN + 1];
int parent[MAXN + 1];
int sz[MAXN + 1];
vector<pair<int, long long>> tree[MAXN + 1];
int anc[LOGN + 1][MAXN + 1];
long long mx[LOGN + 1][MAXN + 1];
int level[MAXN + 1];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int x, int y)
{
    int r1 = getRoot(x);
    int r2 = getRoot(y);
    if (r1 == r2)
        return;
    if (sz[r1] < sz[r2])
        swap(r1, r2);
    parent[r2] = r1;
    sz[r1] += sz[r2];
}

void dfs(int v, int p, int l)
{
    anc[0][v] = p;
    level[v] = l;
    for (pair<int, long long> edge : tree[v])
    {
        int adj = edge.first;
        if (adj != p)
        {
            mx[0][adj] = edge.second;
            dfs(adj, v, l + 1);
        }
    }
}

long long solve(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);
    int diff = level[a] - level[b];
    long long ans = 0;
    for (int i = LOGN; i >= 0; i--)
    {
        if (diff & (1 << i))
        {
            ans = max(ans, mx[i][a]);
            a = anc[i][a];
        }
    }
    if (a != b)
    {
        for (int i = LOGN; i >= 0; i--)
        {
            if (anc[i][a] != anc[i][b])
            {
                ans = max(ans, max(mx[i][a], mx[i][b]));
                a = anc[i][a];
                b = anc[i][b];
            }
        }
        ans = max(ans, max(mx[0][a], mx[0][b]));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist + 1, dist + n + 1, 1E18);
    for (int i = 1; i <= k; i++)
    {
        from[i] = i;
        dist[i] = 0;
        pq.push(make_pair(0, i));
    }
    vector<tuple<long long, int, int>> edges;
    while (!pq.empty())
    {
        pair<long long, int> pr = pq.top();
        pq.pop();
        int v = pr.second;
        long long d = pr.first;
        if (visited[v])
            continue;
        visited[v] = true;
        for (pair<int, int> edge : adjList[v])
        {
            int u = edge.first;
            int w = edge.second;
            if (visited[u] && from[u] != from[v])
            {
                edges.push_back(make_tuple(dist[v] + dist[u] + w, from[u], from[v]));
            }
            else if (!visited[u])
            {
                if (d + w < dist[u])
                {
                    pq.push(make_pair(d + w, u));
                    dist[u] = d + w;
                    from[u] = from[v];
                }
            }
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= k; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (tuple<long long, int, int> t : edges)
    {
        long long d = get<0>(t);
        int u = get<1>(t);
        int v = get<2>(t);
        if (getRoot(u) != getRoot(v))
        {
            tree[u].push_back(make_pair(v, d));
            tree[v].push_back(make_pair(u, d));
            mge(u, v);
        }
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][anc[i - 1][j]]);
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}