#include<bits/stdc++.h>
#define N 100010
#define M 5000010
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
using namespace std;
bitset<M> vis, used;
bitset<N> day[55];
// bool [M];

int n, m, d, low[M], dfn[M], tot, bh[M], cnt, stot, st[M], dp[M], val[M];
int head[M], edge_id;
struct node {
    int to, next;
} e[M];

void add_edge(int u, int v) { // 
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}

int gw(int x) { return (x - 1) % n + 1; } // 
int gd(int x) { return (x - 1) / n + 1; } // 

inline void dfs(int x) { // tarjan ,  QAQ
    low[x] = dfn[x] = ++tot, st[++stot] = x, vis[x] = 1;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(!dfn[v]) dfs(v), low[x] = min(low[x], low[v]);
        else if(vis[v]) low[x] = min(low[x], dfn[v]);
    }
    if(low[x] == dfn[x]) {
        int now = stot, pp;
        ++cnt;
        while(st[now] != x) {
            pp = st[now], bh[pp] = cnt, vis[pp] = 0, --now;
            if(!used[gw(pp)] && day[gd(pp)][gw(pp)]) 
                used[gw(pp)] = 1, val[cnt]++;
        }
        bh[x] = cnt, vis[x] = 0, --now;
        if(!used[gw(x)] && day[gd(x)][gw(x)]) used[gw(x)] = 1, val[cnt]++;
        L(i, now, stot) used[gw(st[i])] = 0;
        stot = now;
    }
}

int hd[M], eid;
struct ndeo {
    int to, next;
} g[M];

void ad_edge(int u, int v) { // 
    ++eid, g[eid].next = hd[u], g[eid].to = v, hd[u] = eid;
}

inline int DFS(int x) { // DFS 
    if(vis[x]) return dp[x];
    for(int i = hd[x]; i; i = g[i].next) dp[x] = max(DFS(g[i].to), dp[x]);
    vis[x] = 1, dp[x] += val[x];
    return dp[x];
}

void rebuild() { // 
    L(i, 1, n * d) for(int j = head[i]; j; j = e[j].next) {
        int v = e[j].to;
        if(bh[i] != bh[v]) ad_edge(bh[i], bh[v]);
    }
}

char s[55];
int main() {
    scanf("%d%d%d", &n, &m, &d);
    L(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        L(j, 1, d) add_edge(n * (j - 1) + u, n * (j % d) + v); // 
    }
    L(i, 1, n) {
        scanf("%s", s + 1);
        L(j, 1, d) day[j][i] = (s[j] == '1');
    }
    L(i, 1, n * d) if(!dfn[i]) dfs(i);
    rebuild();
    vis.reset();
    printf("%d\n", DFS(bh[1])); 
    return 0;
}