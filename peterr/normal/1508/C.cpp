#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int LOGN = 18;
int anc[LOGN][MAXN + 1];
tuple<int, int, int> edges[MAXN];
vector<pair<int, int>> adjList[MAXN + 1];
bool visited[MAXN + 1];
int par[MAXN + 1];
int sz[MAXN + 1];
bool neigh[MAXN + 1];
set<int> looking;
vector<pair<int, int>> tree[MAXN + 1];
int dep[MAXN + 1];
int val[MAXN + 1];
bool used[MAXN];

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

void mge(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return;
    if (sz[x] < sz[y])
        swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
}

int dfs(int v)
{
    int ans = 0;
    visited[v] = true;
    for (pair<int, int> edge : adjList[v])
    {
        neigh[edge.first] = true;
    }
    vector<int> vec;
    for (int x : looking)
    {
        if (neigh[x])
            continue;
        ans++;
        vec.push_back(x);
        tree[v].push_back({x, 1});
        tree[x].push_back({v, 1});
        mge(x, v);
    }
    for (int x : vec)
        looking.erase(looking.find(x));
    for (pair<int, int> edge : adjList[v])
    {
        neigh[edge.first] = false;
    }
    for (int adj : vec)
    {
        if (!visited[adj])
            ans += dfs(adj);
    }
    return ans;
}

void dfs2(int v, int p, int d)
{
    dep[v] = d;
    for (pair<int, int> edge : tree[v])
    {
        int adj = edge.first;
        if (adj == p)
            continue;
        val[adj] = val[v] + edge.second;
        dfs2(adj, v, d + 1);
        anc[0][adj] = v;
    }
}

int lca(int u, int v)
{
    if (u == v)
        return u;
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    for (int i = 0; i < LOGN; i++)
    {
        if (diff & (1 << i))
            u = anc[i][u];
    }
    if (u == v)
        return u;
    for (int i = LOGN - 1; i >= 0; i--)
    {
        if (anc[i][u] != anc[i][v])
        {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    return anc[0][u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        sz[i] = 1;
        par[i] = i;
    }
    int x = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        edges[i] = {w, u, v};
        x ^= w;
    }
    long long totalEdges = (long long) n * (n - 1) / 2;
    int cnt = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            looking.clear();
            for (int j = 1; j <= n; j++)
            {
                if (!visited[j] && j != i)
                    looking.insert(j);
            }
            cnt += dfs(i);
        }
    }
    sort(edges, edges + m);
    for (int i = 0; i < m; i++)
    {
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);
        if (getRoot(u) == getRoot(v))
            continue;
        used[i] = true;
        ans += get<0>(edges[i]);
        mge(u, v);
        tree[u].push_back({v, 0});
        tree[v].push_back({u, 0});
    }
    if (cnt + m == totalEdges)
    {
        dfs2(1, 1, 0);
        anc[0][1] = 1;
        for (int i = 1; i < LOGN; i++)
        {
            for (int j = 1; j <= MAXN; j++)
            {
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (used[i])
                continue;
            int u = get<1>(edges[i]);
            int v = get<2>(edges[i]);
            int l = lca(u, v);
            if (val[u] + val[v] - val[l])
            {
                x = min(x, get<0>(edges[i]));
                break;
            }
        }
        ans += x;
    }
    cout << ans << "\n";
    return 0;
}