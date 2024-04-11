#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5, lgn = 20;
int n, m, q;
int low[maxn + 10], dfn[maxn + 10], dcnt;
int id[maxn + 10], nn;
int co, bel[maxn + 10], f[maxn + 10][lgn + 1], dep[maxn + 10];
bool is[maxn + 10], isrt[maxn + 10];
int s[maxn + 10][2];
vector<int> z[maxn + 10];

struct edge {
	int to, id;
};
vector<edge> g[maxn + 10];

void dfs(int p, int fa) {
	dfn[p] = low[p] = ++dcnt;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.id != fa) {
			if (!dfn[e.to]) {
				dfs(e.to, e.id);
				low[p] = min(low[p], low[e.to]);
				if (low[e.to] > dfn[p]) is[e.id] = 1;
			} else low[p] = min(low[p], dfn[e.to]);
		}
	}
}

void dfs2(int p, int v) {
	id[p] = v;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (!is[e.id] && !id[e.to]) dfs2(e.to, v);
	}
}

void dfslca(int p) {
	bel[p] = co; dep[p] = dep[f[p][0]] + 1;
	for (int i = 1; i <= lgn; ++i) f[p][i] = f[f[p][i - 1]][i - 1];
	for (int i = 0; i < (int)z[p].size(); ++i) {
		int e = z[p][i];
		if (e != f[p][0]) {
			f[e][0] = p; dfslca(e);
		}
	}
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

void ddfs(int p) {
	for (int i = 0; i < (int)z[p].size(); ++i) {
		int e = z[p][i];
		if (e != f[p][0]) {
			ddfs(e);
			s[p][0] += s[e][0]; s[p][1] += s[e][1];
		}
	}
	if ((!!s[p][0]) && (!!s[p][1])) {
		printf("No"); exit(0);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back((edge){r, i});
		g[r].push_back((edge){l, i});
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) dfs(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!id[i]) {
			++nn; dfs2(i, nn);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < (int)g[i].size(); ++j) {
			edge e = g[i][j];
			if (is[e.id]) z[id[i]].push_back(id[e.to]);
		}
	for (int i = 1; i <= nn; ++i)
		if (!bel[i]) {
			++co; isrt[i] = 1;
			dfslca(i);
		}
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		x = id[x]; y = id[y];
		if (bel[x] != bel[y]) {
			printf("No"); return 0;
		}
		int p = lca(x, y);
		++s[x][0]; --s[p][0];
		++s[y][1]; --s[p][1];
	}
	for (int i = 1; i <= nn; ++i)
		if (isrt[i]) ddfs(i);
	printf("Yes");
}