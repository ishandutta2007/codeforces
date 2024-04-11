#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

typedef long long ll;
const int N = 10005, M = N * 3, Inf = 0x3f3f3f3f;

int n, m, s, t;
int a[N], b[N], c[N], l[N], r[N], idx, st[N];
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
ll dfs(int u, ll lim, ll re = 0) {
	if(u == t) return lim;
	for(int& i = nw[u], v; v = e[i].v; i = e[i].nx)
	if(e[i].c && d[v] == d[u] + 1) {
		ll t = dfs(v, min((ll)e[i].c, lim));
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
	cin >> n >> m;
	s = ++idx, t = ++idx;
	rep(i, 1, n) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	rep(i, 1, n) {
		scanf("%d%d", &l[i], &r[i]);
		add(s, ++idx, Inf * 2), st[i] = idx + 1 - l[i];
		rep(j, l[i], r[i])
			add(idx, idx + 1, Inf - a[i] * j * j - b[i] * j - c[i]), idx++;
		add(idx, t, Inf * 2);
	}
	int u, v, d;
	while(m--) {
		scanf("%d%d%d", &u, &v, &d);
		rep(i, max(l[u] - d, l[v]) - 1, min(r[u] - d, r[v]))
			add(st[u] + i + d, st[v] + i, Inf * 2);
	}
	ll as = (ll)Inf * n;
	while(bfs()) as -= dfs(s, Inf * 2);
	cout << as;
	return 0;
}