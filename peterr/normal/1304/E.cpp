#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int LOGN = 18;
vector<int> adjList[MAXN + 1];
bool color[MAXN + 1];
int level[MAXN + 1];
int anc[LOGN + 1][MAXN + 1];

void dfs(int v, int p, bool c, int l)
{
    anc[0][v] = p;
    color[v] = c;
    level[v] = l;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            dfs(adj, v, !c, l + 1);
        }
    }
}

int dist(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    int diff = level[u] - level[v];
    int ans = 0;
    for (int i = 0; i <= LOGN; i++)
    {
        if (diff & (1 << i))
        {
            ans += (1 << i);
            u = anc[i][u];
        }
    }
    for (int i = LOGN; i >= 0; i--)
    {
        if (anc[i][u] != anc[i][v])
        {
            u = anc[i][u];
            v = anc[i][v];
            ans += (1 << (i + 1));
        }
    }
    if (u != v)
        ans += 2;
    return ans;
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
    dfs(1, 1, true, 0);
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int d = dist(a, b);
        int bridge = min(dist(a, x) + dist(y, b), dist(a, y) + dist(x, b)) + 1;
        bool par1 = color[x] == color[y];
        bool par2 = (d + k) % 2 != 0;
        bool ans = true;
        if (par2 && !par1)
            ans = false;
        else if (par2 && par1)
            ans = bridge <= k;
        else if (!par2 && par1)
            ans = d <= k;
        else if (!par2 && !par1)
            ans = min(d, bridge) <= k;
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}