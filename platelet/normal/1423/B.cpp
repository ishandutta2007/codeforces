#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e4 + 5, M = N * 2 + 1e5;
int n, m, g[M];
int eid = 1, he[N * 2], cur[N * 2], dis[N * 2], s, t;
struct edge { int v, nxt, w, flow; } e[M * 2];
void adde(int u, int v, int w) {
	e[++eid] = { v, he[u], w };
	he[u] = eid;
}
void add(int u, int v, int w) { adde(u, v, w), adde(v, u, w); }
int dfs(int u, int lim, int res = 0) {
	if(u == t) return lim;
	for(int i = cur[u], v; (v = e[i].v) && lim && (cur[u] = i); i = e[i].nxt)
	if(e[i].flow && dis[v] == dis[u] + 1) {
		int t = dfs(v, min(lim, e[i].flow));
		if(!t) dis[v] = -1;
		e[i].flow -= t, e[i ^ 1].flow += t, res += t, lim -= t;
	}
	return res;
}
int bfs() {
	static int q[N * 2];
	mem(dis, 0), memcpy(cur, he, sizeof he);
	dis[q[1] = s] = 1;
	for(int l = 1, r = 1; l <= r; l++)
	for(int i = cur[q[l]], v; (v = e[i].v); i = e[i].nxt)
	if(e[i].flow && !dis[v]) {
		dis[v] = dis[q[l]] + 1;
		if((q[++r] = v) == t) return 1;
	}
	return 0;
}
int chk(int mid, int res = 0) {
	rep(i, 2, eid) e[i].flow = i % 2 == 0 && e[i].w <= g[mid];
	while(bfs()) res += dfs(s, n);
	return res == n;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	s = n * 2 + 1, t = s + 1;
	rep(i, 1, n) add(s, i, 0), add(i + n, t, 0);
	rep(i, 1, m) {
		scanf("%d%d%d", &u, &v, &g[i]);
		add(u, v + n, g[i]);
	}
	sort(g + 1, g + m + 1);
	if(!chk(m)) puts("-1"), exit(0);
	int l = 1, r = m, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(chk(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << g[l];
	return 0;
}