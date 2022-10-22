#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 110, Inf = 0x3f3f3f3f;

int n, K, L[N], R[N];
int eid = 1, he[N], nw[N];
struct edge { int v, nx, c, w; } e[N * N + N];
void add(int u, int v, int c, int w) {
	e[++eid] = {v, he[u], c, w}, he[u] = eid;
	e[++eid] = {u, he[v], 0, -w}, he[v] = eid;
}
int s, t, d[N], q[N], vs[N], flow, as;
int spfa() {
	mem(d, 63), memcpy(nw, he, sizeof he);
	q[1] = s, d[s] = 0, vs[s] = 1;
	for(int l = 1, r = 1; l <= r; l++) {
		int u = q[l]; vs[u] = 0;
		for(int i = he[u], v; (v = e[i].v); i = e[i].nx)
		if(e[i].c && d[u] + e[i].w < d[v]) {
			d[v] = d[u] + e[i].w;
			if(!vs[v]) q[++r] = v, vs[v] = 1;
		}
	}
	return d[t] < Inf;
}
int dfs(int u, int lim, int re = 0) {
	if(u == t) return lim;
	vs[u] = 1;
	for(int& i = nw[u], v; (v = e[i].v); i = e[i].nx)
	if(!vs[v] && e[i].c && d[v] == d[u] + e[i].w) {
		int t = dfs(v, min(lim, e[i].c));
		e[i].c -= t, e[i ^ 1].c += t, re += t, as += t * e[i].w;
		if(re == lim) break;
	}
	if(re < lim) d[u] = Inf;
	vs[u] = 0;
	return re;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	rep(i, 1, n) L[i] = 1, R[i] = n;
	int ty, l, r, v;
	while(K--) {
		scanf("%d%d%d%d", &ty, &l, &r, &v);
		rep(i, l, r) ty == 1 ? L[i] = max(L[i], v) : R[i] = min(R[i], v);
	}
	s = n * 2 + 1, t = s + 1;
	rep(i, 1, n) {
		if(L[i] > R[i]) puts("-1"), exit(0);
		add(s, i, 1, 0);
		rep(j, 1, n) add(i + n, t, 1, j * 2 - 1);
		rep(j, L[i], R[i]) add(i, j + n, 1, 0);
	}
	while(spfa()) dfs(s, Inf, 0);
	cout << as;
	return 0;
}