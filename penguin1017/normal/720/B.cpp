#include <bits/stdc++.h>

#define MAXN 10050
#define MAXM 20050

using namespace std;

struct Edge {
    int v, id, next;
} edge[MAXM * 2];
int e, ft[MAXN];
int n, m, cnt, dfn[MAXN], low[MAXN];
int dsu[MAXM], col[MAXM], size[MAXM];
bool flag[MAXM];

int find(int k)
{
    return dsu[k] ^ k ? dsu[k] = find(dsu[k]) : k;
}

void merge(int u, int v) {
    u = find(col[u]);
    v = find(col[v]);
    flag[u] = (u ^ v) ? (flag[u] | flag[v]) : true;
    dsu[v] = u;
}

void add(int u, int v, int id)
{
    edge[e].v = v;
    edge[e].id = id;
    edge[e].next = ft[u];
    ft[u] = e++;
}

void dfs(int u, int pre) {
    low[u] = dfn[u] = ++cnt;
    int id;
    for (int i = ft[u]; i != -1; i = edge[i].next) {
        if ((id = edge[i].id) == pre)
            continue;
        int v = edge[i].v;
        if (dfn[v] == -1) {
            dfs(v, edge[i].id);
            if (low[v] < dfn[u]) {
                low[u] = min(low[u], low[v]);
                merge(pre, id);
            } else if (low[v] == dfn[v]) {
                flag[find(col[id])] = true;
            }
        } else if (dfn[v] < dfn[u]) {
            low[u] = min(low[u], dfn[v]);
            merge(id, pre);
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2) {
        e = 0;
        memset(ft, -1, sizeof(ft));
        int u, v, c;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &c);
            add(u, v, i);
            add(v, u, i);
            col[i] = c;
            flag[i] = false;
            dsu[i] = i;
            size[c] = 1;
        }
        cnt = 0;
        memset(dfn, -1, sizeof(dfn));
        dfs(1, -1);
				
        int ans = 0;
        for (int i = 1; i <= m; i++)
            if (size[i] && find(i) == i)
                ans -= !flag[i];
		
		for (int i= 1; i <= m; i++)	ans+= size[i];
		
        printf("%d\n", ans);
    }
    return 0;
}