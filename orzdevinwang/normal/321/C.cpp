#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 2e5 + 7;
int n, m, maxsiz, rt, fn, siz[N], col[N];
struct node { int to, next; } e[N << 1];
int edge_id, head[N];
void add_edge(int u, int v) { ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; }
void DFS(int x, int fa) {
    siz[x] = 1;
    for(int i = head[x]; i; i = e[i].next) if(e[i].to != fa && col[e[i].to] == -1) DFS(e[i].to, x), siz[x] += siz[e[i].to];
}
void findrt(int x, int fa) {
    siz[x] = 1;
    int maxn = 0;
    for(int i = head[x]; i; i = e[i].next) if(e[i].to != fa && col[e[i].to] == -1) {
        int v = e[i].to;
        findrt(v, x), siz[x] += siz[v], maxn = max(maxn, siz[v]);
    }
    maxn = max(maxn, fn - siz[x]);
    if(maxn < maxsiz) maxsiz = maxn, rt = x;
}
void dfs(int x, int now) {
    if(fn == 1) return col[x] = now, void();
    maxsiz = 1e9, findrt(x, -1), col[rt] = now, DFS(rt, -1);
    for(int i = head[rt]; i; i = e[i].next) if(col[e[i].to] == -1) fn = siz[e[i].to], dfs(e[i].to, now + 1);
}
int main() {
    scanf("%d", &n);
    L(i, 1, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    L(i, 1, n) col[i] = -1;
    fn = n, dfs(1, 0);
    L(i, 1, n) putchar('A' + col[i]), putchar(' ');
    return 0;
}