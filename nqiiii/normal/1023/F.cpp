#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000;
int n, k, m, l[maxn + 10], r[maxn + 10], w[maxn + 10];;
int fa[maxn + 10], dep[maxn + 10], faid[maxn + 10], ans[maxn + 10];
bool b[maxn + 10];
long long tot;

struct edge {
	int to, id;
};

vector<edge> g[maxn + 10];

struct dsu {
	int fa[maxn + 10];

	void init() {
		for (int i = 1; i <= n; ++i) fa[i] = i;
	}

	int getf(int p) {
		return fa[p] == p ? p : fa[p] = getf(fa[p]);
	}

	void merge(int x, int y) {
		fa[getf(x)] = getf(y);
	}
}o, u;

void dfs(int p) {
	dep[p] = dep[fa[p]] + 1;
	for (int i = 0; i < g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != fa[p]) {
			fa[e.to] = p; faid[e.to] = e.id;
			dfs(e.to);
		}
	}
}

void jump(int x, int y, int w) {
	x = u.getf(x); y = u.getf(y);	
	while (x != y) {
		if (dep[x] < dep[y]) swap(x, y);
		ans[faid[x]] = w; u.merge(x, fa[x]);
		x = u.getf(x);
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	o.init(); u.init();
	for (int i = 1; i <= k; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back((edge){r, i});
		g[r].push_back((edge){l, i});
		o.merge(l, r);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &w[i]);
		if (o.getf(l[i]) == o.getf(r[i])) b[i] = 1;
		else {
			g[l[i]].push_back((edge){r[i], 0});
			g[r[i]].push_back((edge){l[i], 0});
			o.merge(l[i], r[i]);
		}
	}
	dfs(1);
	for (int i = 1; i <= m; ++i)
		if (b[i]) jump(l[i], r[i], w[i]);
	for (int i = 1; i <= k; ++i)
		if (ans[i]) tot += ans[i];
		else {
			printf("-1"); return 0;
		}
	printf("%lld", tot);
}