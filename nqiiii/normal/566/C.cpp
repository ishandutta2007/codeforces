#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, w[maxn + 10], sz[maxn + 10];
int mnv, mnid;
bool vis[maxn + 10];
double nowa, ans = 1e100;
int pos;

struct edge {
	int to, len;
};
vector<edge> g[maxn + 10];

void dfssz(int p) {
	vis[p] = 1; sz[p] = 1;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (!vis[e.to]) {
			dfssz(e.to); sz[p] += sz[e.to];
		}
	}
	vis[p] = 0;
}

void dfsrt(int p, int all) {
	vis[p] = 1; int now = all - sz[p];
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (!vis[e.to]) {
			dfsrt(e.to, all); now = max(now, sz[e.to]);
		}
	}
	if (now < mnv) {
		mnv = now; mnid = p;
	}
	vis[p] = 0;
}

double dfscalc(int p, int fa, int d) {
	double ans = w[p] * sqrt(d);
	nowa += w[p] * sqrt(d) * d;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != fa)
			ans += dfscalc(e.to, p, d + e.len);
	}
	return ans;
}

void divide(int p) {
	dfssz(p); mnv = 1e9;
	dfsrt(p, sz[p]); p = mnid;
	vis[p] = 1; nowa = 0;
	double mxd = -1e100; int to = 0;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		edge e = g[p][i];
		double v = dfscalc(e.to, p, e.len);
		if (!vis[e.to] && v > mxd) {
			mxd = v; to = e.to;
		}
	}
	if (nowa < ans) {
		ans = nowa; pos = p;
	}
	if (to) divide(to);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
	for (int i = 1; i < n; ++i) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);
		g[l].push_back((edge){r, w});
		g[r].push_back((edge){l, w});
	}
	divide(1);
	printf("%d %.10lf", pos, ans);
}