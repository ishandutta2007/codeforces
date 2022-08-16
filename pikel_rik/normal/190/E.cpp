#include <bits/stdc++.h>
using namespace std;

struct S {
	vector<int> forward_par, reverse_par;
	S(int n) : forward_par(n + 2), reverse_par(n + 2) {
		iota(forward_par.begin(), forward_par.end(), 0);
		iota(reverse_par.begin(), reverse_par.end(), 0);
	}

	int forward_find(int x) {
		return x == forward_par[x] ? x : forward_par[x] = forward_find(forward_par[x]);
	}

	int reverse_find(int x) {
		return x == reverse_par[x] ? x : reverse_par[x] = reverse_find(reverse_par[x]);
	}

	void del(int i) {
		reverse_par[i] = i - 1, forward_par[i] = i + 1;
	}

	int operator[](int i) {
		return forward_find(i);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n + 1);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	vector<bool> visited(n + 1);
	vector<vector<int>> final;

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		final.emplace_back();
		auto &comp = final.back();

		S list(n);

		auto dfs = [&](int x, const auto &self) -> void {
			visited[x] = true;
			comp.push_back(x);
			for (int i = list[1]; i <= n; i = list[i + 1]) {
				if (!binary_search(g[x].begin(), g[x].end(), i)) {
					list.del(i);
					self(i, self);
				}
			}
		};

		list.del(i);
		dfs(i, dfs);
	}

	cout << final.size() << '\n';
	for (auto &v : final) {
		cout << v.size() << ' ';
		for (auto &x : v) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}