#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 20005, M = N * 4, Inf = 0x3f3f3f3f;

int n, m, g, s, t;
int x[N], v[N];
int eid = 1, he[N], nw[N], d[N], q[N];
struct edge { int v, nx, c; } e[M * 2];

void add(int u, int v, int c) {
	e[++eid] = {v, he[u], c}, he[u] = eid;
	e[++eid] = {u, he[v], 0}, he[v] = eid;
}
int bfs() {
	mem(d, 0), memcpy(nw, he, sizeof he);
	q[1] = s, d[s] = 1;
	for(int l = 1, r = 1; l <= r; l++) {
		int u = q[l];
		for(int i = he[u], v; v = e[i].v; i = e[i].nx)
		if(e[i].c && !d[v]) q[++r] = v, d[v] = d[u] + 1;
	}
	return d[t];
}
int dfs(int u, int lim, int re = 0) {
	if(u == t) return lim;
	for(int& i = nw[u], v; v = e[i].v; i = e[i].nx)
	if(e[i].c && d[v] == d[u] + 1) {
		int t = dfs(v, min(e[i].c, lim));
		e[i].c -= t, e[i ^ 1].c += t, re += t, lim -= t;
		if(!lim) break;
	}
	if(lim) d[u] = 0;
	return re;
}

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m >> g;
	s = n + m + 1, t = s + 1;
	rep(i, 1, n) scanf("%d", &x[i]);
	rep(i, 1, n) scanf("%d", &v[i]), x[i] ? add(s, i, v[i]) : add(i, t, v[i]);
	int p, w, k, e, flow = 0;
	rep(i, 1, m) {
		scanf("%d%d%d", &p, &w, &k), flow += w;
		while(k--) scanf("%d", &e), p ? add(i + n, e, Inf) : add(e, i + n, Inf);
		scanf("%d", &e), p ? add(s, i + n, w + e * g) : add(i + n, t, w + e * g);
	}
	while(bfs()) flow -= dfs(s, Inf);
	cout << flow;
	return 0;
}