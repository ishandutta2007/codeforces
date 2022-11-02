#include <cstdio>
#include <vector>

using namespace std;
const int N = 2e6 + 100;

vector <int> edges[N], divisors[N], last[N];
int a[N], ans[N], deep[N];

void build(int x)
{
    for (int i = 0; i < divisors[x].size(); i++)
    {
        int o = divisors[x][i];
        if (last[o].size() != 0)
        {
            if (ans[x] == -1 || deep[ans[x]] < deep[last[o][last[o].size() - 1]]) ans[x] = last[o][last[o].size() - 1];
        }
        last[o].push_back(x);
    }
    for (int i = 0; i < edges[x].size(); i++)
    {
        int to = edges[x][i];
        if (deep[to] < deep[x]) continue;
        build(to);
    }
    for (int i = 0; i < divisors[x].size(); i++) last[divisors[x][i]].pop_back();
}

void factor(int x)
{
    divisors[x].clear();
    for (int i = 2; i * i <= a[x]; i++) if (a[x] % i == 0)
    {
        divisors[x].push_back(i);
        while (a[x] % i == 0) a[x] /= i;
    }
    if (a[x] != 1) divisors[x].push_back(a[x]);
}

void dfs(int x, int d)
{
    deep[x] = d;
    for (int i = 0; i < edges[x].size(); i++)
    {
        int to = edges[x][i];
        if (deep[to] == 0) dfs(to, d + 1);
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        factor(i);
    }
    for (int i = 1; i < n; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) ans[i] = -1;
    build(1);
    for (int i = 1; i <= q; i++)
    {
        int type, v1, v2;
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d", &v1);
            printf("%d\n", ans[v1]);
            continue;
        }
        scanf("%d %d", &v1, &v2);
        a[v1] = v2;
        factor(v1);
        for (int i = 1; i <= n; i++) ans[i] = -1;
        build(1);
    }
    return 0;
}