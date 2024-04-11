// sto George1123 orz
// George1123's  : https://www.cnblogs.com/George1123/p/12813027.html /qq /qq /qq
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int P = 222;
const int N = 2e4 + 7;
const int M = N * 6;
const int inf = 2e8;
const ll linf = 1e12;
int tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, next; ll val;
} e[M << 1];
void add_edge(int u, int v, ll val) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, ll val) {
	add_edge(u, v, val), add_edge(v, u, 0);
}
int dis[N], cur[N];
bool bfs() {
	fill(dis + 1, dis + tot + 1, inf);
	copy(head + 1, head + tot + 1, cur + 1);
	queue<int> q; q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(e[i].val && dis[v] >= inf) dis[v] = dis[u] + 1, q.push(v);
		}
	}
	return dis[t] < inf;
}
ll dfs(int x, ll flow) {
	if(x == t) return flow;
	ll now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		ll fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	return flow - now;
}
ll dinic() {
	ll res = 0;
	while(bfs()) res += dfs(s, linf);
	return res;
}
int n, m, a[P], b[P], c[P], l[P], r[P], G[P][P];
int f(int i, int x) { return inf - x * x * a[i] - x * b[i] - c[i]; }
int main() {
	scanf("%d%d", &n, &m), s = ++tot, t = ++tot;
	L(i, 1, n) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	L(i, 1, n) {
		scanf("%d%d", &l[i], &r[i]);
		L(j, l[i], r[i]) G[i][j + 100] = ++tot;
		G[i][r[i] + 101] = t;
		add(s, G[i][l[i] + 100], linf);
		L(j, l[i], r[i]) add(G[i][j + 100], G[i][j + 101], f(i, j));
	}
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		L(j, l[u], r[u]) if(j - val >= l[v]) {
			if(j - val > r[v]) add(G[u][j + 100], t, linf);
			else add(G[u][j + 100], G[v][j - val + 100], linf);
		}
	}
	printf("%lld\n", 1ll * inf * n - dinic());
	return 0;
}
/*
3 3
0 1 0
0 1 1
0 1 2
0 3
1 2
-3 3
1 2 0
2 3 0
3 1 0
/shAKe
*/