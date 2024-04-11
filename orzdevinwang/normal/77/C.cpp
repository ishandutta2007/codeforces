#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
ll dp[N];
int n, m, st, k[N], deg[N];
struct node { int to, next; } e[N << 1];
int head[N], edge_id;
void add_edge(int u, int v) { ++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id; }
int tot, f[N];
void dfs(int x, int fa) {
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        deg[v]--, k[v]--;
        dfs(v, x);
    }
    if(k[x] < deg[x]) {
        tot = 0;
        for(int i = head[x]; i; i = e[i].next) if(e[i].to != fa) f[++tot] = dp[e[i].to];
        sort(f + 1, f + tot + 1), reverse(f + 1, f + tot + 1);
        for(int i = 1; i <= k[x]; i++) dp[x] += f[i] + 2;
        k[x] = 0;
    }
    else {
        k[x] -= deg[x];
        for(int i = head[x]; i; i = e[i].next) {
            int v = e[i].to;
            if(v == fa) continue;
            dp[x] += dp[v] + 2;
            int maxn = min(k[x], k[v]);
            dp[x] += 2 * maxn, k[x] -= maxn;
        }
    }
    // cout << x << " " << dp[x] << endl;
}
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &k[i]);
    L(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v), deg[u]++, deg[v]++;
        add_edge(u, v), add_edge(v, u);
    }
    scanf("%d", &st);
    dfs(st, -1);
    printf("%lld\n", dp[st]);
    return 0;
}