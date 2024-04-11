#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 5555;
int n;
int head[N], edge_id;
struct node {
    int to, next;
} e[N << 1];
void add_edge(int u, int v) {
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; 
}
int p[N][N], siz[N][N];
ll dp[N][N];
void DFS(int u, int x, int fa) {
    siz[u][x] = 1, p[u][x] = fa;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        DFS(u, v, x), siz[u][x] += siz[u][v];
    }
}
ll dfs(int u, int v) {
    if(u == v) return 0;
    if(u > v) swap(u, v);
    if(dp[u][v]) return dp[u][v];
    return dp[u][v] = max(dfs(v, p[v][u]), dfs(u, p[u][v])) + siz[u][v] * siz[v][u];
}
int main() {
    scanf("%d", &n);
    L(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    L(i, 1, n) DFS(i, i, 0);
    ll ans = 0;
    L(i, 1, n) L(j, i + 1, n) ans = max(ans, dfs(i, j));
    printf("%lld\n", ans);
    return 0;
}