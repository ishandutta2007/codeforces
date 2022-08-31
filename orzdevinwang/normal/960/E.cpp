#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
int n, m, a[N], sum[N], ans[N], sz[N], Ans;
int head[N], edge_id;
struct node {
    int to, next;
} e[N << 1];
void add_edge(int u, int v) {
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x, int fa) {
    sz[x] = 1;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, x), sz[x] += sz[v], (sum[x] += mod - sum[v]) %= mod;
    }
    (sum[x] += 1ll * a[x] * sz[x] % mod) %= mod;
}
void DFS(int x, int fa) {
    (Ans += ans[x]) %= mod;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        int gg = (ans[x] + mod - (mod - sum[v] + 1ll * a[x] * sz[v] % mod) % mod) % mod;
        ans[v] = ((sum[v] + mod - gg) % mod + 1ll * a[v] * (n - sz[v]) % mod) % mod; 
        DFS(v, x);
    }
}
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]), a[i] = (mod + a[i]) % mod;
    int u, v;
    L(i, 1, n - 1) scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
    dfs(1, 0), ans[1] = sum[1], DFS(1, 0);
    printf("%d\n", Ans);
    return 0;
}