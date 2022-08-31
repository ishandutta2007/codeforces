#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
int n, m, st, sz[N];
struct node { int to, t, next; } e[N << 1];
int head[N], edge_id;
void add_edge(int u, int v, int val) { 
    ++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], e[edge_id].t = val, head[u] = edge_id; 
}
int tot;
ll dp[N], tim[N];
struct getmax {
    ll t; int sz;
} f[N];
bool operator < (getmax aa, getmax bb) { return aa.t * bb.sz < aa.sz * bb.t; }
void dfs(int x, int fa) {
    sz[x] = 1;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, x), sz[x] += sz[v], dp[x] += dp[v] + sz[v] * e[i].t;
    }
    tot = 0;
    for(int i = head[x]; i; i = e[i].next) if(e[i].to != fa) f[++tot].t = tim[e[i].to] + e[i].t * 2, f[tot].sz = sz[e[i].to];
    sort(f + 1, f + tot + 1);
    L(i, 1, tot) dp[x] += tim[x] * f[i].sz, tim[x] += f[i].t;
}
int main() {
    scanf("%d", &n);
    L(i, 1, n - 1) {
        int u, v, val; scanf("%d%d%d", &u, &v, &val);
        add_edge(u, v, val), add_edge(v, u, val);
    }
    dfs(1, -1);
    printf("%.10lf\n", 1.0 * dp[1] / (n - 1));
    return 0;
}