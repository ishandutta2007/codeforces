#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 2e5 + 10;

int n;
long long ans, s0, c0, s1, c1;
vector<int> g[maxn];
bool vis[maxn];

int cen(int u) {
	static int q[maxn], par[maxn], fnt, rar, sz[maxn], hs[maxn];
	fnt = rar = 0;
	q[rar++] = u; par[u] = 0;
	while(fnt != rar) {
		u = q[fnt++];
		sz[u] = 1; hs[u] = 0;
		for (int v: g[u]) if(!vis[v] && v != par[u]) q[rar++] = v, par[v] = u;
	}
	for (int i = rar - 1; ~i; --i) {
		u = q[i];
		if(max(hs[u], rar - sz[u]) * 2 <= rar) return u;
		int p = par[u];
		hs[p] = max(hs[p], sz[u]);
		sz[p] += sz[u];
	}
}

void dfs1(int u, int p, int d = 1) {
	ans += (d + 1 >> 1);
	if(d & 1) {
		ans += (long long) ((d >> 1) + 1) * (c0 + c1) + s0 + s1;
	}
	else {
		ans += (long long) (d >> 1) * (c0 + c1) + s0 + s1 + c1;
	}
	for (int v: g[u]) if(!vis[v] && v != p) {
		dfs1(v, u, d + 1);
	}
	return;
}

void dfs2(int u, int p, int d = 1) {
	if(d & 1) {
		s1 += (d >> 1);
		++c1;
	}
	else s0 += (d >> 1), ++c0;
	for (int v: g[u]) if(!vis[v] && v != p) {
		dfs2(v, u, d + 1);
	}
}

void work(int u) {
	u = cen(u);
#ifdef DEBUG
	printf("work(%d)\n", u);
#endif
	s0 = s1 = c0 = c1 = 0;
	for (int v: g[u]) if(!vis[v]) {
		dfs1(v, u);
		dfs2(v, u);
	}
	vis[u] = 1;
#ifdef DEBUG
	printf("ans = %"LLFORMAT"d\n", ans);
#endif
	for (int v: g[u]) if(!vis[v]) work(v);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) { int u, v; scanf("%d%d", &u, &v); g[u].push_back(v), g[v].push_back(u); }
	work(1);
	printf("%"LLFORMAT"d\n", ans);
	return 0;
}