#include <cstdio>
#include <vector>

using namespace std;
const int N = 2e5;

int cnt[N];
vector <int> edges[N], res;
bool used[N];

void add(int x)
{
    cnt[x] = (cnt[x] + 1) % 2;
    res.push_back(x);
}

void dfs(int ver, int par)
{
    used[ver] = true;
    add(ver);
    for (int i = 0; i < edges[ver].size(); i++)
    {
        int to = edges[ver][i];
        if (used[to]) continue;
        dfs(edges[ver][i], ver);
        add(ver);
    }
    if (ver == par) return;
    if (cnt[ver] == 1) add(par), add(ver);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int v, e;
        scanf("%d %d", &v, &e);
        edges[v].push_back(e);
        edges[e].push_back(v);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &cnt[i]);
    int go = 0;
    for (int i = 1; i <= n; i++) if (cnt[i] == 1) go = i;
    if (go != 0) dfs(go, go);
    int start;
    if (cnt[go] == 0) start = 0; else
    {
        start = 1;
        cnt[go] = 0;
    }
    for (int i = 1; i <= n; i++) if (cnt[i] == 1)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", res.size() - start);
    for (int i = start; i < res.size(); i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}