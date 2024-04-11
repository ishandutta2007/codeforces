#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
int n, m, sz[N], dep[N], jp[20][N];
ll sum[N], nsum[N];
int head[N], edge_id;
struct node {
    int to, next;
} e[N << 1];
void add_edge(int u, int v) {
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x, int fa) {
    sz[x] = 1, dep[x] = dep[fa] + 1, jp[0][x] = fa;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, x);
        sz[x] += sz[v], sum[x] += sum[v] + sz[v];
    }
}
void DFS(int x, int fa) {
    ll gg = 0;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        nsum[v] = nsum[x] + (sum[x] - sum[v] - sz[v]) + (n - sz[v]);
        DFS(v, x);
    }
}
void work(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    int dx = x, dy = y, len = 0;
    R(i, 18, 0) if(dep[dx] - dep[dy] > (1 << i)) dx = jp[i][dx], len += (1 << i);
    if(jp[0][dx] == dy) printf("%.10lf\n", 1.0 * sum[x] / sz[x] + 1.0 * (sum[y] - sz[dx] - sum[dx] + nsum[y]) / (n - sz[dx]) + len + 2);
    else {
        if(dep[dx] != dep[dy]) dx = jp[0][dx], len++;
        R(i, 18, 0) if(jp[i][dx] != jp[i][dy]) dx = jp[i][dx], dy = jp[i][dy], len += (2 << i);
        dx = jp[0][dx], dy = jp[0][dy], len += 2;
        printf("%.10lf\n", 1.0 * sum[x] / sz[x] + 1.0 * sum[y] / sz[y] + len + 1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    L(i, 1, n - 1) scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
    dfs(1, 0), DFS(1, 0);
    L(i, 1, 18) L(j, 1, n) jp[i][j] = jp[i - 1][jp[i - 1][j]];
    while(m--) scanf("%d%d", &u, &v), work(u, v);
    return 0;
}