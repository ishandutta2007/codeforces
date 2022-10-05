#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct edge {
	int to;
	ll w;
	edge() {}
	edge(int tt, ll ww) {
		to = tt;
		w = ww;
	}
};

struct maxflow {
	int n, limit;
	vector<int> vis;
	vector<edge> e, mem;
	vector<vector<int>> g;

	int unvis[55] = {}, nxt = 0;

	maxflow(int sz = 1, int lim = 1) {
		n = sz;
		limit = lim;
		nxt = 0;
		g.resize(n);
		vis.resize(n, 0);
	}
	void add(int u, int v, int w) {
		g[u].push_back(e.size());
		e.emplace_back(v, w);
		g[v].push_back(e.size());
		e.emplace_back(u, 0);
	}
	void fin() {
		mem = e;
	}
	bool dfs(int v, int w) {
		if (v == n - 1) return true;
		if (vis[v]) return false;
		vis[v] = 1;
		unvis[nxt++] = v;
		for (const auto &i : g[v]) {
			if (e[i].w >= w) {
				e[i].w -= w;
				e[1 ^ i].w += w;
				if (dfs(e[i].to, w)) return true;
				e[1 ^ i].w -= w;
				e[i].w += w;
			}
		}
		return false;
	}
	void debugedges() {
		cout << "debuggin'" << endl;
		for (int i = 0; i < n; i++)
			for (const auto &j : g[i]) {
				cout << i << " to " << e[j].to << " is " << e[j].w << endl;
			}
	}
	bool check(ldb w) {
//		cout << "checking " << w << endl;
		for (auto &i : e)
			i.w = ll(i.w / w);
		int cnt = 0, flow = 1000000;
		while (cnt < limit && flow > 0) {
			if (dfs(0, flow))
				cnt += flow;
			else
				flow /= 2;
			while (nxt > 0) nxt--, vis[unvis[nxt]] = 0;
		}
		while (nxt > 0) nxt--, vis[unvis[nxt]] = 0;
		e = mem;
		return cnt >= limit;
	}
};

int n, m, x;
maxflow M;

int main() {
	fast;
	cout.precision(8);
	cin >> n >> m >> x;
	M = maxflow(n, x);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		--u, --v;
		M.add(u, v, w);
	}
	M.fin();
	ldb lo = 1.0 / x, hi = 1000004, mid;
	int iter = 100;
	while (abs(lo - hi) > eps && iter > 0) {
		iter--;
		mid = (lo + hi) / 2;
		if (M.check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo * x << endl;
}