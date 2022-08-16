#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct fenwick_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> bit;
	F f;

	fenwick_tree() : n(), f() {}
	fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

	void add(int i, T val) {
		for (++i; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}

	T query(int i) {
		T ans = 0;
		for (++i; i; i -= i & -i) {
			ans = f(ans, bit[i]);
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n), add(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int timer = 0;
	vector<int> tin(n), tout(n), sz(n);

	auto first_dfs = [&](int x, int p, const auto &dfs) -> void {
		tin[x] = timer++;
		sz[x] = 1;
		for (int i : g[x]) {
			if (i == p) continue;
			dfs(i, x, dfs);
			sz[x] += sz[i];
		}
		tout[x] = timer++;
	};

	first_dfs(0, -1, first_dfs);

	auto f = [&](int u, int v) -> bool {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	int a, b;
	while (m--) {
		cin >> a >> b;
		--a, --b;
		add[a].push_back(b);
		add[b].push_back(a);
		add[a].push_back(a);
		add[b].push_back(b);
	}

	vector<int> c(n);
	fenwick_tree<int> ft(2 * n), anc(2 * n);

	auto second_dfs = [&](int x, int p, const auto &dfs) -> void {
		vector<pair<int, int>> added;
		for (int i : add[x]) {
			int q = ft.query(tout[i]) - ft.query(tin[i] - 1);
			if (anc.query(tin[i]) == 0) {
				ft.add(tin[i], sz[i] - q);
				anc.add(tin[i], 1);
				anc.add(tout[i], -1);
				added.emplace_back(i, q);
			}
		}
		c[x] = max(0, ft.query(2 * n - 1) - 1);
		for (int i : g[x]) {
			if (i == p) continue;
			dfs(i, x, dfs);
		}

		for (auto&[i, q] : added) {
			anc.add(tin[i], -1);
			anc.add(tout[i], 1);
			ft.add(tin[i], q - sz[i]);
		}
	};

	second_dfs(0, -1, second_dfs);
	for (int i = 0; i < n; i++) cout << c[i] << " \n"[i + 1 == n];
	return 0;
}