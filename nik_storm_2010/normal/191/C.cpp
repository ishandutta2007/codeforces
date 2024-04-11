#include <cstdio>
#include <vector>

using namespace std;
const int N = 2e5;
const int LOG = 18;

int up[N][LOG], change[N], tin[N], tout[N], ans[N], timer;
vector <int> edges[N], num[N];

void prepare(int x, int prev)
{
    tin[x] = timer++;
    up[x][0] = prev;
    for (int i = 1; i < LOG; i++) up[x][i] = up[up[x][i - 1]][i - 1];
    for (int i = 0; i < edges[x].size(); i++)
    {
        int to = edges[x][i];
        if (to == prev) continue;
        prepare(to, x);
    }
    tout[x] = timer++;
}

bool ancestor(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (ancestor(x, y)) return x;
    if (ancestor(y, x)) return y;
    for (int i = LOG - 1; i >= 0; i--) if (ancestor(up[x][i], y) == false) x = up[x][i];
    return up[x][0];
}

void dfs(int x, int prev)
{
    for (int i = 0; i < edges[x].size(); i++)
    {
        int to = edges[x][i], nom = num[x][i];
        if (to == prev) continue;
        dfs(to, x);
        ans[nom] = change[to];
        change[x] += change[to];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        num[x].push_back(i);
        edges[y].push_back(x);
        num[y].push_back(i);
    }
    prepare(1, 1);
    int quests;
    scanf("%d", &quests);
    for (int quest = 1; quest <= quests; quest++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int common = lca(x, y);
        change[x]++;
        change[y]++;
        change[common] -= 2;
    }
    dfs(1, 1);
    for (int i = 1; i < n; i++) printf("%d ", ans[i]);
    return 0;
}