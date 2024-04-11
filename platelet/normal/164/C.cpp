#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1005, Inf = 0x3f3f3f3f;

int n, K, l[N], r[N], c[N], g[N], x[N];
int eid = 1, he[N], nw[N];
struct edge { int v, nx, c, w; } e[N * 4];
void add(int u, int v, int c, int w) {
	e[++eid] = {v, he[u], c, w}, he[u] = eid;
	e[++eid] = {u, he[v], 0, -w}, he[v] = eid;
}
int s, t, d[N], q[N], vs[N], flow;
int spfa() {
	mem(d, 63), memcpy(nw, he, sizeof he);
	q[0] = s, d[s] = 0, vs[s] = 1;
	for(int l = 0, r = 0; l <= r; l++) {
		int u = q[l % n]; vs[u] = 0;
		for(int i = he[u], v; (v = e[i].v); i = e[i].nx)
		if(e[i].c && d[u] + e[i].w < d[v]) {
			d[v] = d[u] + e[i].w;
			if(!vs[v]) q[++r % n] = v, vs[v] = 1;
		}
	}
	return d[t] < Inf;
}
int dfs(int u, int lim, int re = 0) {
	if(u == t) return lim;
	vs[u] = 1;
	for(int& i = nw[u], v; v = e[i].v; i = e[i].nx)
	if(!vs[v] && e[i].c && d[v] == d[u] + e[i].w) {
		int t = dfs(v, min(lim, e[i].c));
		e[i].c -= t, e[i ^ 1].c += t, re += t;
		if(re == lim) break;
	}
	if(re < lim) d[u] = Inf;
	vs[u] = 0;
	return re;
}
int main() {
	cin >> n >> K;
	rep(i, 1, n) scanf("%d%d%d", &l[i], &r[i], &c[i]), g[i] = l[i];
	sort(g + 1, g + n + 1);
	auto id = [](int x) { return lower_bound(g + 1, g + n + 1, x) - g; };
	rep(i, 1, n) add(id(l[i]), id(l[i] + r[i]), 1, -c[i]), x[i] = eid;
	rep(i, 1, n + 1) add(i, i + 1, K, 0);
	s = 1, t = n + 2;
	while(spfa()) dfs(s, Inf);
	rep(i, 1, n) printf("%d ", e[x[i]].c);
	return 0;
}