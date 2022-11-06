#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int LOGN = 19;
const int INF = MAXN + 5;
vector<int> adjList[MAXN + 1];
int dist[MAXN + 1];
int par[MAXN + 1];
int sz[MAXN + 1];
bool centVisited[MAXN + 1];
pair<int, int> val[MAXN + 1];
vector<pair<int, int>> st[MAXN + 1];
int anc[LOGN][MAXN + 1];
int depth[MAXN + 1];
int ans[MAXN + 1];

void buildAnc(int v, int p, int dep)
{
    depth[v] = dep;
    anc[0][v] = p;
    for (int i = 1; i < LOGN; i++)
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        buildAnc(adj, v, dep + 1);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOGN; i++)
    {
        if (diff & (1 << i))
            a = anc[i][a];
    }
    if (a == b)
        return a;
    for (int i = LOGN - 1; i >= 0; i--)
    {
        if (anc[i][a] != anc[i][b])
        {
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

int distBetween(int a, int b)
{
    int l = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[l];
}

void dfs(int v, int p)
{
    sz[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj == p || centVisited[adj])
            continue;
        dfs(adj, v);
        sz[v] += sz[adj];
    }
}

int getCentroid(int v, int p, int n)
{
    for (int adj : adjList[v])
    {
        if (adj == p || centVisited[adj])
            continue;
        if (sz[adj] > n / 2)
            return getCentroid(adj, v, n);
    }
    return v;
}

int buildTree(int v, int n)
{
    dfs(v, v);
    int root = getCentroid(v, v, n);
    centVisited[root] = true;
    dfs(root, root);
    for (int adj : adjList[root])
    {
        if (centVisited[adj])
            continue;
        par[buildTree(adj, sz[adj])] = root;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    fill(dist + 1, dist + n + 1, INF);
    int k;
    cin >> k;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        q.push(x);
        dist[x] = 0;
    }
    buildAnc(1, 1, 0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int adj : adjList[v])
        {
            if (dist[adj] != INF)
                continue;
            q.push(adj);
            dist[adj] = dist[v] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        val[i] = make_pair(dist[i], i);
    }
    sort(val + 1, val + n + 1);
    int root = buildTree(1, n);
    par[root] = root;
    for (int i = 1; i <= n; i++)
    {
        int value = val[i].first;
        int node = val[i].second;
        int cur = node;
        while (1)
        {
            int d = value - distBetween(node, cur) - 1;
            if (d >= 0)
            {
                while (!st[cur].empty() && st[cur].back().first == value && st[cur].back().second <= d)
                    st[cur].pop_back();
                if (st[cur].empty() || st[cur].back().first < value)
                {
                    while (!st[cur].empty() && st[cur].back().second <= d)
                        st[cur].pop_back();
                    st[cur].push_back(make_pair(value, d));
                }
            }
            if (par[cur] == cur)
                break;
            cur = par[cur];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 0)
            ans[i] = 0;
        else
        {
            int cur = i;
            while (1)
            {
                int d = distBetween(i, cur);
                if (!st[cur].empty())
                {
                    int ind = -1;
                    for (int jump = (int) st[cur].size() / 2 + 1; jump; jump >>= 1)
                    {
                        while (ind + jump < (int) st[cur].size() && st[cur][ind + jump].second >= d)
                            ind += jump;
                    }
                    if (ind != -1)
                    {
                        ans[i] = max(ans[i], st[cur][ind].first);
                    }
                }
                if (par[cur] == cur)
                    break;
                cur = par[cur];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}