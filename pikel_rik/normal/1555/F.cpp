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

struct union_find {
	int n, c;
	std::vector<int> p, r;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	bool merge(int x, int y) {
		int l1 = find(x);
		int l2 = find(y);
		if (l1 == l2)
			return false;
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			p[l2] = l1;
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
		}
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	struct edge {
		int u, v, x;
	};

	int n, q;
	cin >> n >> q;

	vector<edge> e(q);
	vector<bool> ans(q);

	union_find uf(n);
	vector<vector<int>> g(n);

	for (int i = 0; i < q; i++) {
		cin >> e[i].u >> e[i].v >> e[i].x;
		--e[i].u, --e[i].v;
		if (uf.merge(e[i].u, e[i].v)) {
			g[e[i].u].push_back(i);
			g[e[i].v].push_back(i);
			ans[i] = true;
		}
	}

	int lg = 32 - __builtin_clz(n);

	int timer = 0;
	vector<int> xor_d(n), tin(n), tout(n);
	vector<vector<int>> up(n, vector<int>(lg, -1));

	auto dfs = [&](int u, const auto &self) -> void {
		tin[u] = timer++;
		for (int i = 1; i < lg && up[u][i - 1] != -1; i++) {
			up[u][i] = up[up[u][i - 1]][i - 1];
		}
		for (int i : g[u]) {
			int v = e[i].u ^ e[i].v ^ u;
			if (v != up[u][0]) {
				up[v][0] = u;
				xor_d[v] = e[i].x ^ xor_d[u];
				self(v, self);
			}
		}
		tout[u] = timer++;
	};

	for (int u = 0; u < n; u++) {
		if (up[u][0] == -1) {
			dfs(u, dfs);
		}
	}

	auto is_anc = [&](int u, int v) -> bool {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	auto lca = [&](int u, int v) -> int {
		if (is_anc(u, v)) {
			return u;
		} else if (is_anc(v, u)) {
			return v;
		}
		for (int i = lg - 1; i >= 0; i--) {
			if (up[u][i] != -1 && !is_anc(up[u][i], v)) {
				u = up[u][i];
			}
		}
		return up[u][0];
	};

	fenwick_tree<int> ft(2 * n);

	auto mark_path = [&](int u, int v) -> bool {
		int l = lca(u, v);
		int used = ft.query(tin[u]) + ft.query(tin[v]) - 2 * ft.query(tin[l]);
		if (used > 0) {
			return false;
		}
		for (int x = u; x != l; x = up[x][0]) {
			ft.add(tin[x], 1), ft.add(tout[x] + 1, -1);
		}
		for (int x = v; x != l; x = up[x][0]) {
			ft.add(tin[x], 1), ft.add(tout[x] + 1, -1);
		}
		return true;
	};

	for (int i = 0; i < q; i++) {
		if (!ans[i]) {
			int u = e[i].u, v = e[i].v;
			int x = xor_d[u] ^ xor_d[v] ^ e[i].x;
			ans[i] = x == 1 && mark_path(u, v);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << (ans[i] ? "YES" : "NO") << '\n';
	}
	return 0;
}