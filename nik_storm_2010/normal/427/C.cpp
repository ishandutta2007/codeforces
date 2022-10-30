#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <memory.h>
#include <iostream>

using namespace std;
const int N = 300000;
const int md = 1e9 + 7;
const int oo = 2e9;

vector <int> edges[N], inv[N], order;
bool used[N];
int cost[N], guy[N], comp[N], sz, op[N], low[N];

void dfs1(int v)
{
	used[v] = true;
	for (int i = 0; i < edges[v].size(); i++)
    {
        int to = edges[v][i];
        if (!used[to]) dfs1(to);
    }
    order.push_back(v);
}

void dfs2(int v)
{
	used[v] = true;
	comp[v] = sz;
	for (int i = 0; i < inv[v].size(); i++)
    {
        int to = inv[v][i];
        if (!used[to]) dfs2(to);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        inv[b].push_back(a);
    }
    memset(used, false, sizeof(used));
    order.clear();
    for (int i = 1; i <= n; i++) if (!used[i]) dfs1(i);
    memset(used, false, sizeof(used));
    sz = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[order[n - i]])
        {
            sz++;
            dfs2(order[n - i]);
        }
    }
    for (int i = 0; i < N; i++) low[i] = oo, op[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cost[i] == low[comp[i]]) op[comp[i]]++;
        if (cost[i] < low[comp[i]])
        {
            low[comp[i]] = cost[i];
            op[comp[i]] = 1;
        }
    }
    long long ans = 0, cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (low[i] == oo) continue;
        ans += low[i];
        cnt = (cnt * op[i]) % md;
    }
    printf("%I64d %I64d\n", ans, cnt);
    return 0;
}