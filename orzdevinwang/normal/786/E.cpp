#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
const int M = 1e6 + 7;
const int inf = 1e4;
int tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, next, val;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].val = val, e[edge_id].next = head[u], head[u] = edge_id;
}
void add(int u, int v, int val) {
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
int dfs(int x, int flow) {
	if(x == t) return flow;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		cur[x] = i;
		int v = e[i].to;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	return flow - now;
}
int dinic() {
	int res = 0;
	while(bfs()) res += dfs(s, inf);
	return res;
}
int n, m;
int dep[N], id[N], Did[N], idtot, maxto[N], fa[N], heavy[N], siz[N];
int U[N], V[N], LCA[N], E[N], G[N];
struct segmenttree {
	bool flag;
	void build(int id, int L, int R) {
		if(L == R) {
			if(flag == 0) add(id + (2 * n), Did[L], inf);
			if(flag == 1) add(Did[L] + n, id + (6 * n), inf);
			return;
		}
		int mid = (L + R) / 2;
		if(flag == 0) add(id + (2 * n), (id << 1) + (2 * n), inf), add(id + (2 * n), (id << 1 | 1) + (2 * n), inf);
		if(flag == 1) add((id << 1) + (6 * n), id + (6 * n), inf), add((id << 1 | 1) + (6 * n), id + (6 * n), inf);
		build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R);
	}
	void Add(int id, int L, int R, int l, int r, int qwq) {
		if(l <= L && R <= r) {
			if(flag == 0) return add(qwq, id + (2 * n), inf), void();
			if(flag == 1) return add(id + (6 * n), qwq, inf), void();
		}
		int mid = (L + R) / 2;
		if(l <= mid) Add(id << 1, L, mid, l, r, qwq);
		if(r > mid) Add(id << 1 | 1, mid + 1, R, l, r, qwq);
	}
} sega, segb;
map<int, int> mp[N];
vector<int> ve[N];
void dfs1(int u) {
	siz[u] = 1, dep[u] = dep[fa[u]] + 1;
	for(int v : ve[u]) if(v ^ fa[u]) {
		fa[v] = u, add(v, u + n, 1), E[v] = edge_id, dfs1(v), siz[u] += siz[v];
		if(siz[v] > siz[heavy[u]]) heavy[u] = v;
	}
}
void dfs2(int u) {
	id[u] = ++idtot, Did[idtot] = u;
	if(heavy[u]) maxto[heavy[u]] = maxto[u], dfs2(heavy[u]);
	for(int v : ve[u]) if(v ^ fa[u] && v ^ heavy[u]) maxto[v] = v, dfs2(v);
}
int lca(int u, int v) {
	while(maxto[u] != maxto[v]) {
		if(dep[maxto[u]] < dep[maxto[v]]) swap(u, v);
		u = fa[maxto[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return v;
}
bool vis[N];
void fbfs() {
	queue<int> q;
	q.push(s), vis[s] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(e[i].val && !vis[v]) vis[v] = 1, q.push(v);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m), tot = n * 10, s = ++tot, t = ++tot;
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		mp[u][v] = mp[v][u] = i;
		ve[u].push_back(v), ve[v].push_back(u);
	}
	dfs1(1), maxto[1] = 1, dfs2(1);
	segb.flag = 1, sega.build(1, 1, n), segb.build(1, 1, n);
//	cout << "Q\n";
	L(i, 1, m) {
		int u, v, ps = ++tot, pt = ++tot, pss = ++tot; scanf("%d%d", &u, &v), U[i] = u, V[i] = v;
		LCA[i] = lca(u, v);
		add(s, ps, inf), add(ps, pss, 1), G[i] = edge_id, add(pt, t, inf);
//		cout << "Q0\n";
		while(maxto[u] != maxto[LCA[i]]) sega.Add(1, 1, n, id[maxto[u]], id[u], pss), u = fa[maxto[u]];
		if(u != LCA[i]) sega.Add(1, 1, n, id[LCA[i]] + 1, id[u], pss);
		while(maxto[v] != maxto[LCA[i]]) sega.Add(1, 1, n, id[maxto[v]], id[v], pss), v = fa[maxto[v]];
		if(v != LCA[i]) sega.Add(1, 1, n, id[LCA[i]] + 1, id[v], pss);
		u = fa[U[i]], v = fa[V[i]];
//		cout << "Q1\n";
		if(U[i] != LCA[i]) {
			while(maxto[u] != maxto[LCA[i]]) segb.Add(1, 1, n, id[maxto[u]], id[u], pt), u = fa[maxto[u]];
			segb.Add(1, 1, n, id[LCA[i]], id[u], pt);
		}
		if(V[i] != LCA[i]) {
			while(maxto[v] != maxto[LCA[i]]) segb.Add(1, 1, n, id[maxto[v]], id[v], pt), v = fa[maxto[v]];
			segb.Add(1, 1, n, id[LCA[i]], id[v], pt);
		}
//		cout << "Q2\n";
//		while(u != LCA[i]) add(pss, u, inf), u = fa[u], add(u + n, pt, inf);
//		while(v != LCA[i]) add(pss, v, inf), v = fa[v], add(v + n, pt, inf);
	}
	int res = dinic(), cnt = 0;
	fbfs();
	printf("%d\n", res);
	L(i, 1, m) if(vis[e[G[i]].to] != vis[e[G[i] ^ 1].to]) ++cnt;
	printf("%d ", cnt);
	L(i, 1, m) if(vis[e[G[i]].to] != vis[e[G[i] ^ 1].to]) printf("%d ", i);
	puts("");
	printf("%d ", res - cnt);
	L(i, 2, n) if(vis[e[E[i]].to] != vis[e[E[i] ^ 1].to]) printf("%d ", mp[i][fa[i]]);
	puts("");
	return 0;
}