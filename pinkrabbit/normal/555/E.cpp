#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 200005, MM = 200005, MQ = 200005;

int N, M, Q, ok;
int h[MN], nxt[MM * 2], to[MM * 2], usd[MM * 2], tot;
inline void ins(int x, int y) { nxt[++tot] = h[x], to[tot] = y, h[x] = tot; }

int vis[MN], faz[MN], dep[MN];
void DFS(int u) {
	vis[u] = 1;
	for (int i = h[u]; i; i = nxt[i]) if (!vis[to[i]]) {
		usd[i] = usd[i ^ 1] = 1;
		faz[to[i]] = u;
		dep[to[i]] = dep[u] + 1;
		DFS(to[i]);
	}
}

int fa[MN];
int ff(int x) { return fa[x] ? fa[x] = ff(fa[x]) : x; }

std::vector<int> G[MN], V[MN];
int sx[MN], sy[MN], lca[MN];
void Tarjan(int u, int &x, int &y) {
	for (auto v : G[u]) {
		int vx = 0, vy = 0;
		Tarjan(v, vx, vy);
		x += vx, y += vy;
		fa[v] = u;
	}
	for (auto id : V[u]) {
		int o = id < 0, i = o ? -id : id;
		++(o ? y : x);
		if (!lca[i]) lca[i] = u;
		else lca[i] = ff(lca[i]), ++sx[lca[i]], ++sy[lca[i]];
	}
	x -= sx[u], y -= sy[u];
	if (x && y) ok = 0;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q), tot = 1, ok = 1;
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		ins(x, y), ins(y, x);
	}
	for (int i = 1; i <= N; ++i) if (!vis[i])
		dep[i] = 1, DFS(i);
	for (int i = 2; i <= tot; i += 2) if (!usd[i]) {
		int u = ff(to[i]), v = ff(to[i ^ 1]);
		usd[i] = usd[i ^ 1] = 1;
		while (u != v) {
			if (dep[u] < dep[v]) std::swap(u, v);
			u = fa[u] = ff(faz[u]);
		}
	}
	for (int i = 1; i <= N; ++i) if (i == ff(i) && faz[i])
		G[ff(faz[i])].push_back(i);
	for (int i = 1, u, v; i <= Q; ++i) {
		scanf("%d%d", &u, &v);
		u = ff(u), v = ff(v);
		if (u == v) continue;
		V[u].push_back(i);
		V[v].push_back(-i);
	}
	for (int i = 1; i <= N; ++i) if (i == ff(i) && !faz[i]) {
		int x = 0, y = 0;
		Tarjan(i, x, y);
		if (x || y) ok = 0;
	}
	puts(ok ? "Yes" : "No");
	return 0;
}