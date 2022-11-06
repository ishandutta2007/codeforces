#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, lim;
int cnt[10][10], fa[10], res;
int l[10], r[10], ecnt;
int c2[10][10], tot[10], mn[10];
int idl[10][10], idr[10], pm[10];

int digit(int x) {
	return x ? digit(x / 10) + 1 : x % 10;
}

int getf(int p) {
	return fa[p] == p ? p : getf(fa[p]);
}

namespace flow {
	const int maxn = 10000;
	struct edge {
		int to, cp, fl, rev;
	};
	vector<edge> g[maxn + 10];
	int n, s, t, cur[maxn + 10], d[maxn + 10];
	queue<int> q;

	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t;
		for (int i = 1; i <= n; ++i) g[i].clear();
	}

	void adde(int l, int r, int w) {
		g[l].push_back((edge){r, w, 0, (int)g[r].size()});
		g[r].push_back((edge){l, 0, 0, (int)g[l].size() - 1});
	}

 	bool bfs() {
		for (int i = 1; i <= n; ++i) d[i] = i == s ? 0 : -1;
		q.push(s);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			for (int i = 0; i < (int)g[p].size(); ++i) {
				edge e = g[p][i];
				if (e.cp > e.fl && d[e.to] == -1) {
					d[e.to] = d[p] + 1; q.push(e.to);
				}
			}
		}
		return d[t] != -1;
	}

	int dfs(int p, int a) {
		if (p == t) return a;
		int ans = 0;
		for (int &i = cur[p]; i < (int)g[p].size(); ++i) {
			edge &e = g[p][i];
			if (e.cp > e.fl && d[p] + 1 == d[e.to]) {
				int now = dfs(e.to, min(e.cp - e.fl, a));
				e.fl += now; g[e.to][e.rev].fl -= now;
				ans += now; a -= now;
				if (!a) break;
			}
		}
		return ans;
	}

	int solve() {
		int ans = 0;
		while (bfs()) {
			for (int i = 1; i <= n; ++i) cur[i] = 0;
			ans += dfs(s, 1e9);
		}
		return ans;
	}
}

void dfs(int x, int y) {
	if (x == lim + 1) {
		for (int i = 2; i <= lim; ++i)
			if (getf(i) != getf(1)) return;
		for (int i = 1; i <= lim; ++i)
			for (int j = 1; j <= lim; ++j) c2[i][j] = cnt[i][j];
		for (int i = 1; i <= ecnt; ++i) 
			if (!c2[l[i]][r[i]]--) return;
		flow::init(lim * lim + lim + 2, 1, 2);
		int p = 2;
		for (int i = 1; i <= lim; ++i)
			for (int j = 1; j <= lim; ++j) {
				idl[i][j] = ++p;
				flow::adde(1, p, c2[i][j]);
			}
		for (int i = 1; i <= lim; ++i) {
			idr[i] = ++p; flow::adde(p, 2, tot[i] - 1);
		}
		for (int i = 1; i <= lim; ++i)
			for (int j = 1; j <= lim; ++j) {
				flow::adde(idl[i][j], idr[i], inf);
				flow::adde(idl[i][j], idr[j], inf);
			}
		if (flow::solve() != n - lim) return;
		for (int i = 1; i <= ecnt; ++i)
			printf("%d %d\n", mn[l[i]], mn[r[i]]);
		for (int i = 1; i <= lim; ++i) pm[i] = mn[i];
		for (int i = 1; i <= lim; ++i)
			for (int j = 1; j <= lim; ++j) {
				int p = idl[i][j];
				using namespace flow;
				for (int k = 0; k < (int)g[p].size(); ++k) {
					edge e = g[p][k];
					if (e.to == idr[i]) {
						for (int l = 1; l <= e.fl; ++l)
							printf("%d %d\n", ++pm[i], mn[j]);
					} else if (e.to == idr[j]) {
						for (int l = 1; l <= e.fl; ++l)
							printf("%d %d\n", mn[i], ++pm[j]);
					}
				}
			}
		exit(0);
	} else {
		int wx = getf(x), wy = getf(y);
		dfs(y == lim ? x + 1 : x, y == lim ? 1 : y + 1);
		if (wx != wy) {
			fa[wx] = wy;
			l[++ecnt] = x; r[ecnt] = y;
			dfs(y == lim ? x + 1 : x, y == lim ? 1 : y + 1);
			fa[wx] = wx; --ecnt;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		static char s[10];
		scanf("%s", s);
		int x = strlen(s);
		scanf("%s", s);
		int y = strlen(s);
		++cnt[x][y];
	}
	lim = digit(n);
	for (int i = 1; i <= lim; ++i) mn[i] = 1e9;
	for (int i = 1; i <= n; ++i) {
		int v = digit(i);
		++tot[v]; mn[v] = min(mn[v], i);
	}
	for (int i = 1; i <= lim; ++i) fa[i] = i;
	dfs(1, 1);
	printf("-1");
}