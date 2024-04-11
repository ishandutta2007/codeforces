#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5, lgn = 17;
int n, m;
int f[maxn + 10][lgn + 1], dfn[maxn + 10], ed[maxn + 10], dcnt;
int dep[maxn + 10], h[maxn + 10];
int c[maxn + 10];
vector<int> g[maxn + 10];

struct data {
	int x, y, w;
};
vector<data> z[maxn + 10];

void modify(int p, int v) {
	for (; p <= n; p += p & -p) c[p] += v;
}
int query(int p) {
	int ans = 0;
	for (; p; p -= p & -p) ans += c[p];
	return ans;
}

void dfs(int p) {
	dfn[p] = ++dcnt;
	dep[p] = dep[f[p][0]] + 1;
	for (int i = 1; i <= lgn; ++i) f[p][i] = f[f[p][i - 1]][i - 1];
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != f[p][0]) {
			f[e][0] = p; dfs(e);
		}
	}
	ed[p] = dcnt;
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = lgn, t = dep[x] - dep[y]; i >= 0; --i)
		if (t >> i & 1) x = f[x][i];
	if (x == y) return x;
	for (int i = lgn; i >= 0; --i)
		if (f[x][i] != f[y][i]) {
			x = f[x][i]; y = f[y][i];
		}
	return f[x][0];
}

int jump(int x, int y) {
	if (x == y) return 0;
	for (int i = lgn; i >= 0; --i)
		if (dep[f[x][i]] > dep[y]) x = f[x][i];
	return x;
}

void dfs2(int p) {
	int sum = 0;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != f[p][0]) {
			dfs2(e); sum += h[e];
		}
	}
	h[p] = sum;
	for (int i = 0; i < (int)z[p].size(); ++i) {
		data e = z[p][i];
		h[p] = max(h[p], sum - h[jump(e.x, p)] - h[jump(e.y, p)] + query(dfn[e.x]) + query(dfn[e.y]) + e.w);
	}
	modify(dfn[p], sum);
	modify(dfn[p] + 1, -sum);
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != f[p][0]) {
			modify(dfn[e], sum - h[e]);
			modify(ed[e] + 1, h[e] - sum);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i) {
		int x; scanf("%d", &x);
		g[i].push_back(x); g[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= m; ++i) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		z[lca(x, y)].push_back((data){x, y, w});
	}
	dfs2(1);
	printf("\n%d", h[1]);
}