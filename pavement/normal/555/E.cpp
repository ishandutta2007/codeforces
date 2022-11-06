#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, P, cn = 1, idx, link[200005], sz[200005], rin[200005], pos[200005], hv[200005], par[200005], dep[200005], ft1[200005], ft2[200005], anc[200005][25];
bool vis[200005], inc[200005], has[200005];
ii ed[200005];
vector<ii> adj[200005];
vector<int> tadj[200005], nadj[200005];
stack<int> S;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

inline int ls(int x) { return x & -x; }

void ft_upd1(int l, int r) {
	for (; l <= N; l += ls(l)) ft1[l]++;
	for (r++; r <= N; r += ls(r)) ft1[r]--;
}

void ft_upd2(int l, int r) {
	for (; l <= N; l += ls(l)) ft2[l]++;
	for (r++; r <= N; r += ls(r)) ft2[r]--;
}

int ft_qry1(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft1[p];
	return r;
}

int ft_qry2(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft2[p];
	return r;
}

void dir(int n) {
	if (vis[n]) return;
	vis[n] = 1;
	for (auto u : adj[n])
		if (!has[u.second]) {
			tadj[n].pb(u.first);
			has[u.second] = 1;
			dir(u.first);
		}
}

void dfs(int n) {
	bool r = 1;
	rin[n] = ++idx;
	for (auto u : tadj[n]) {
		if (rin[u] == -1) dfs(u);
		if (!inc[u] && rin[u] < rin[n]) rin[n] = rin[u], r = 0;
	}
	if (r) {
		vector<int> v;
		inc[n] = 1;
		v.pb(n);
		while (!S.empty() && rin[n] <= rin[S.top()]) {
			int w = S.top();
			S.pop();
			inc[w] = rin[w] = cn;
			v.pb(w);
		}
		rin[n] = cn;
		sort(v.begin(), v.end());
		for (int i : v)
			for (auto j : tadj[i])
				if (!binary_search(v.begin(), v.end(), j)) {
					nadj[cn].pb(rin[j]);
					nadj[rin[j]].pb(cn);
				}
		cn++;
	} else S.push(n);
}

int dfs2(int n) {
	int sz = 1, mc = 0;
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1)
			anc[n][i] = anc[anc[n][i - 1]][i - 1];
	for (auto u : nadj[n])
		if (u != par[n]) {
			anc[u][0] = n;
			par[u] = n;
			dep[u] = dep[n] + 1;
			int c = dfs2(u);
			sz += c;
			if (c > mc) mc = c, hv[n] = u;
		}
	return sz;
}

void decomp(int n, int h) {
	pos[n] = ++idx;
	if (hv[n] != -1) decomp(hv[n], h);
	for (auto u : nadj[n])
		if (u != par[n] && u != hv[n]) decomp(u, u);
	hv[n] = h;
}

void upd(int u, int v, bool t) {
	if (dep[u] > dep[v]) swap(u, v);
	for (; hv[u] != hv[v]; v = par[hv[v]]) {
		if (dep[hv[u]] > dep[hv[v]]) swap(u, v);
		if (t) ft_upd1(pos[hv[v]], pos[v]);
		else ft_upd2(pos[hv[v]], pos[v]);
	}
	if (dep[u] > dep[v]) swap(u, v);
	if (t) ft_upd1(pos[u] + 1, pos[v]);
	else ft_upd2(pos[u] + 1, pos[v]);
}

ii qry(int u, int v) {
	if (dep[v] > dep[u]) swap(u, v);
	return mp(ft_qry1(pos[u]), ft_qry2(pos[u]));
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[u] - (1<<i) >= dep[v])
			u = anc[u][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
		if (anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

main() {
	memset(anc, -1, sizeof anc);
	memset(rin, -1, sizeof rin);
	memset(hv, -1, sizeof hv);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> P;
	for (int i = 1; i <= N; i++) {
		link[i] = i;
		sz[i] = 1;
	}
	for (int u, v, i = 1; i <= M; i++) {
		cin >> u >> v;
		unite(u, v);
		ed[i] = mp(u, v);
		adj[u].eb(v, i);
		adj[v].eb(u, i);
	}
	for (int i = 1; i <= N; i++) dir(i);
	for (int i = 1; i <= N; i++)
		if (rin[i] == -1) dfs(i);
	cn--;
	idx = 0;
	for (int i = 1; i <= cn; i++)
		if (!par[i]) dfs2(i);
	for (int i = 1; i <= cn; i++)
		if (!par[i]) decomp(i, i);
	for (int X, Y; P--; ) {
		cin >> X >> Y;
		if (find(X) != find(Y)) return cout << "NO\n", 0;
		int Z = lca(rin[X], rin[Y]);
		upd(rin[X], Z, 1);
		upd(Z, rin[Y], 0);
	}
	for (int i = 1; i <= M; i++)
		if (rin[ed[i].first] != rin[ed[i].second]) {
			auto res = qry(rin[ed[i].first], rin[ed[i].second]);
			if (res.first && res.second) return cout << "No\n", 0;
		}
	cout << "Yes\n";
}