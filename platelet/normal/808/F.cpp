#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 105, M = 2e5;
int n, K, f[M + 5], pid, prm[M];
int p[N], c[N], l[N];
int eid, he[N], cur[N], dis[N], q[N], s, t;
struct edge { int v, nxt, flow; } e[N * N];
void adde(int u, int v, int flow) {
	e[++eid] = { v, he[u], flow };
	he[u] = eid;
}
void add(int u, int v, int flow) { adde(u, v, flow), adde(v, u, 0); }
int dfs(int u, int lim, int res = 0) {
	if(u == t) return lim;
	for(int i = cur[u], v; (v = e[i].v) && lim && (cur[u] = i); i = e[i].nxt)
	if(e[i].flow && dis[v] == dis[u] + 1) {
		int t = dfs(v, min(e[i].flow, lim));
		if(!t) dis[v] = 0;
		e[i].flow -= t, e[i ^ 1].flow += t, lim -= t, res += t;
	}
	return res;
}
int bfs() {
	mem(dis, 0), memcpy(cur, he, sizeof he);
	dis[q[1] = s] = 1;
	for(int l = 1, r = 1; l <= r; l++)
	for(int i = he[q[l]], v; (v = e[i].v); i = e[i].nxt)
	if(e[i].flow && !dis[v]) {
		dis[v] = dis[q[l]] + 1;
		if((q[++r] = v) == t) return 1;
	}
	return 0;
}
int chk(int mid, int res = 0) {
	eid = 1, mem(he, 0);
	rep(i, 1, n) if(c[i] > 1 && l[i] <= mid) {
		res += p[i];
		if(c[i] & 1) add(s, i, p[i]);
		else add(i, t, p[i]);
	}
	int ma = 0;
	rep(i, 1, n) if(c[i] == 1 && l[i] <= mid && p[i] > p[ma]) ma = i;
	if(ma) add(s, ma, p[ma]), res += p[ma];
	rep(i, 1, n) if(c[i] % 2 && l[i] <= mid)
	rep(j, 1, n) if(c[j] % 2 == 0 && l[j] <= mid && !f[c[i] + c[j]]) add(i, j, 1e9);
	while(bfs()) res -= dfs(s, 1e9);
	return res >= K;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	rep(i, 2, M) {
		if(!f[i]) prm[++pid] = i;
		for(int j = 1; i * prm[j] <= M; j++) {
			f[i * prm[j]] = 1;
			if(i % prm[j] == 0) break;
		}
	}
	cin >> n >> K, s = n + 1, t = n + 2;
	rep(i, 1, n) scanf("%d%d%d", &p[i], &c[i], &l[i]);
	if(!chk(n)) puts("-1"), exit(0);
	int l = 1, r = n, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(chk(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
}