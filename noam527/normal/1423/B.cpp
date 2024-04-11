#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct edge {
	int v, w;
	edge() {}
	edge(int vv, int ww) {
		v = vv;
		w = ww;
	}
};

struct maxflow {
	int n, S, T;
	vector<edge> e;
	vector<vector<int>> g, gg;
	vector<int> vis, dist;
	maxflow() {}
	maxflow(int sz) {
		n = sz;
		S = 2 * n;
		T = 2 * n + 1;
		g.resize(2 * n + 2);
		gg.resize(2 * n + 2);
		vis.resize(2 * n + 2, 0);
		dist.resize(2 * n + 2);
		for (int i = 0; i < n; i++) {
			addedge(S, i);
			addedge(i + n, T);
		}
	}
	void addedge(int u, int v) {
		g[u].push_back(e.size());
		e.push_back(edge(v, 1));
		g[v].push_back(e.size());
		e.push_back(edge(u, 0));
	}
	bool bfs() {
		queue<int> q;
		for (auto &i : gg) i.clear();
		q.push(S);
		for (auto &i : vis) i = 0;
		vis[S] = 1;
		dist[S] = 0;
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (const auto &i : g[x]) {
				if (e[i].w && !vis[e[i].v]) {
					vis[e[i].v] = 1;
					dist[e[i].v] = 1 + dist[x];
					q.push(e[i].v);
				}
			}
		}
		if (!vis[T]) return false;
		for (int i = 0; i < 2 * n + 2; i++) {
			for (const auto &j : g[i]) {
				if (e[j].w && dist[i] + 1 == dist[e[j].v]) {
					gg[i].push_back(j);
				}
			}
		}
		return true;
	}
	bool dfs(int v) {
		if (v == T) return true;
		if (vis[v]) return false;
		vis[v] = 1;
		while (gg[v].size()) {
			int i = gg[v].back();
			gg[v].pop_back();
			if (dfs(e[i].v)) {
				e[i].w = 0;
				e[1 ^ i].w = 1;
				return true;
			}
		}
		return false;
	}
	int work() {
		int ans = 0;
		while (bfs()) {
			if (OO) cout << "new bfs worked: dist = " << dist[T] << '\n';
			for (auto &i : vis) i = 0;
			while (dfs(S)) {
				ans++;
				for (auto &i : vis) i = 0;
			}
		}
		return ans;
	}
};

int n, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	vector<vector<int>> e(m);
	for (auto &i : e) {
		i.resize(3);
		cin >> i[1] >> i[2] >> i[0];
		--i[1], --i[2];
	}
	sort(e.begin(), e.end());

	if (OO) {
		cout << "testall:\n";
		maxflow M(n);
		for (int i = 0; i < m; i++) {
			M.addedge(e[i][1], e[i][2] + n);
		}
		cout << M.work() << '\n';
	}

	int lo = 0, hi = m, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		maxflow M(n);
		for (int i = 0; i <= mid; i++) {
			M.addedge(e[i][1], e[i][2] + n);
		}
		if (M.work() == n)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (lo == m) cout << "-1\n";
	else cout << e[lo][0] << '\n';
}