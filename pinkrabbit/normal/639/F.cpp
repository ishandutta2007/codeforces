#include <cstdio>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> pii;
const int MN = 300005;

int N, M, Q;
std::vector<pii> G[MN];
std::vector<int> T[MN];

int stk[MN], tp;
int dfn[MN], low[MN], dfc;
int idu[MN], bel[MN], cnt;
int faz[MN];
void Tarjan(int u, int li) {
	low[u] = dfn[u] = ++dfc;
	stk[++tp] = u;
	for (auto e : G[u]) {
		int v = e.first, i = e.second;
		if (!dfn[v]) {
			faz[v] = u;
			Tarjan(v, i);
			low[u] = std::min(low[u], low[v]);
			if (low[v] > dfn[u]) {
				idu[++cnt] = v;
				for (int x = 0; x != v; --tp) {
					x = stk[tp];
					bel[x] = cnt;
				}
			}
		} else if (i != li) low[u] = std::min(low[u], dfn[v]);
	}
}

int tfaz[MN], dep[MN], siz[MN], son[MN], tdfn[MN], top[MN], tdfc;
void DFS0(int u, int f) {
	dep[u] = dep[tfaz[u] = f] + 1;
	siz[u] = 1;
	for (auto v : T[u]) {
		DFS0(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void DFS1(int u, int t) {
	tdfn[u] = ++tdfc;
	top[u] = t;
	if (son[u]) DFS1(son[u], t);
	for (auto v : T[u]) if (v != son[u]) DFS1(v, v);
}
inline int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = tfaz[top[x]];
		if (!x) return 0;
	}
	return dep[x] < dep[y] ? x : y;
}

int _bel[MN];

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		if (x != y)
			G[x].push_back({y, i}),
			G[y].push_back({x, i});
	}
	for (int i = 1; i <= N; ++i) if (!dfn[i]) {
		Tarjan(i, 0);
		idu[++cnt] = i;
		while (tp) bel[stk[tp--]] = cnt;
	}
	for (int i = 1; i <= cnt; ++i)
		if (faz[idu[i]]) T[bel[faz[idu[i]]]].push_back(i);
		else DFS0(i, 0), DFS1(i, i);
	for (int i = 1; i <= N; ++i) _bel[i] = bel[i];
	long long Rval = 0;
	for (int q = 1; q <= Q; ++q) {
		int n, m, c = 0;
		static int x[MN], a[MN], b[MN], d[MN * 3];
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x[i]);
			x[i] = (x[i] + Rval - 1) % N + 1;
			d[++c] = x[i] = _bel[x[i]];
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			a[i] = (a[i] + Rval - 1) % N + 1;
			b[i] = (b[i] + Rval - 1) % N + 1;
			d[++c] = a[i] = _bel[a[i]];
			d[++c] = b[i] = _bel[b[i]];
		}
		std::sort(d + 1, d + c + 1, [](int i, int j) { return tdfn[i] < tdfn[j]; });
		c = std::unique(d + 1, d + c + 1) - d - 1;
		static int vstk[MN]; int vtp = 0, edg = 0, X;
		for (int i = 1; i <= c; ++i) {
			int u = d[i];
			G[u].clear(), dfn[u] = 0;
			if (!vtp) vstk[vtp = 1] = u;
			else {
				int l = lca(vstk[vtp], u);
				if (!l) {
					for (X = 0; vtp; X = vstk[vtp--]) if (X)
						G[vstk[vtp]].push_back({X, ++edg}),
						G[X].push_back({vstk[vtp], edg});
					vstk[vtp = 1] = u;
					continue;
				}
				for (X = 0; vtp && dep[vstk[vtp]] > dep[l]; X = vstk[vtp--]) if (X)
					G[vstk[vtp]].push_back({X, ++edg}),
					G[X].push_back({vstk[vtp], edg});
				if (!vtp || vstk[vtp] != l) vstk[++vtp] = l, G[l].clear(), dfn[l] = 0;
				if (X)
					G[vstk[vtp]].push_back({X, ++edg}),
					G[X].push_back({vstk[vtp], edg});
				vstk[++vtp] = u;
			}
		}
		for (X = 0; vtp; X = vstk[vtp--]) if (X)
			G[vstk[vtp]].push_back({X, ++edg}),
			G[X].push_back({vstk[vtp], edg});
		for (int i = 1; i <= m; ++i)
			if (a[i] != b[i])
				G[a[i]].push_back({b[i], ++edg}),
				G[b[i]].push_back({a[i], edg});
		cnt = 0;
		for (int i = 1; i <= n; ++i) if (!dfn[x[i]]) {
			Tarjan(x[i], 0);
			idu[++cnt] = x[i];
			while (tp) bel[stk[tp--]] = cnt;
		}
		int ok = 1;
		for (int i = 1; i <= n; ++i)
			if (bel[x[i]] != bel[x[1]]) { ok = 0; break; }
		if (ok) puts("YES"), Rval += q;
		else puts("NO");
	}
	return 0;
}