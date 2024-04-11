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

	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};


constexpr int N = 100000;

int n, k, d[N], timer, tin[N], tout[N], up[N][20];
vector<int> g[N];

void dfs(int x, int p) {
	up[x][0] = p;
	for (int i = 1; up[x][i - 1] != -1; i++) up[x][i] = up[up[x][i - 1]][i - 1];
	tin[x] = timer++;
	for (int i : g[x]) {
		if (i != p) {
			d[i] = 1 + d[x];
			dfs(i, x);
		}
	}
	tout[x] = timer++;
}

inline bool f(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (f(u, v)) return u;
	if (f(v, u)) return v;
	for (int i = 19; i >= 0; i--) {
		if (up[u][i] != -1 && !f(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

int sz, leader;
fenwick_tree<int> ft;

void add(int x) {
	if (sz == 0) {
		leader = x, sz++;
		ft.add(tin[x], 1);
		return;
	}

	if (x == leader) {
		ft.add(tin[x], 1);
		return;
	}

	if (f(leader, x)) {
		if (!ft.query(tin[x], tout[x])) {
			int temp = x;
			for (int i = 19; i >= 0; i--) {
				int nxt = up[temp][i];
				if (nxt != -1 && !ft.query(tin[nxt], tout[nxt])) {
					temp = nxt;
				}
			}
			temp = up[temp][0];
			sz += d[x] - d[temp];
		}
	} else {
		if (f(x, leader)) {
			sz += d[leader] - d[x];
			leader = x;
		} else {
			int l = lca(x, leader);
			sz += d[x] + d[leader] - 2 * d[l];
			leader = l;
		}
	}
	ft.add(tin[x], 1);
}

void rem(int x) {
	if (sz == 1) {
		sz = 0;
		ft.add(tin[x], -1);
		return;
	}

	ft.add(tin[x], -1);
	int new_leader = x + 1, total = ft.query(tin[0], tout[0]);

	if (ft.query(tin[new_leader], tout[new_leader]) != total) {
		for (int i = 19; i >= 0; i--) {
			int nxt = up[new_leader][i];
			if (nxt != -1 && ft.query(tin[nxt], tout[nxt]) != total) {
				new_leader = nxt;
			}
		}
		new_leader = up[new_leader][0];
	}

	if (f(x, new_leader)) {
		sz -= d[new_leader] - d[x];
	} else {
		if (!f(new_leader, x)) {
			int l = lca(x, new_leader);
			sz -= d[x] + d[new_leader] - 2 * d[l];
		} else {
			if (!ft.query(tin[x], tout[x])) {
				int temp = x;
				for (int i = 19; i >= 0; i--) {
					int nxt = up[temp][i];
					if (nxt != -1 && !ft.query(tin[nxt], tout[nxt])) {
						temp = nxt;
					}
				}
				temp = up[temp][0];
				sz -= d[x] - d[temp];
			}
		}
	}
	leader = new_leader;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(up, -1, sizeof(up));

	dfs(0, -1);
	ft = fenwick_tree<int>(timer);

	int ans = 1;
	add(0);
	for (int l = 0, r = 0; r + 1 < n;) {
		while (r + 1 < n) {
			add(++r);
			if (sz > k) break;
			ans = max(ans, r - l + 1);
		}
		while (sz > k) {
			rem(l++);
		}
		ans = max(ans, r - l + 1);
	}

	cout << ans << '\n';
	return 0;
}