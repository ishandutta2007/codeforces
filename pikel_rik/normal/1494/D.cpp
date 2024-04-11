#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int vertices = n;
	vector<pair<int, int>> edges;

	vector<int> cost(n);
	for (int i = 0; i < n; i++) {
		cost[i] = a[i][i];
	}

	vector<int> p(n);
	vector<vector<int>> c(n);

	auto merge = [&](int x, int y) -> void {
		if (p[x] == p[y])
			return;
		if (c[x].size() < c[y].size())
			swap(x, y);
		for (auto &i : c[y])
			c[x].push_back(i), p[i] = x;
		c[y].clear();
	};

	auto recurse = [&](vector<int> v, const auto &self) -> int {
		if (v.size() == 1)
			return v.front();

		int max_sal = 0;
		for (int i : v) {
			for (int j : v) {
				max_sal = max(max_sal, a[i][j]);
			}
		}

		for (int i : v) {
			p[i] = i, c[i] = {i};
		}

		for (int i : v) {
			for (int j : v) {
				if (a[i][j] != max_sal) {
					merge(i, j);
				}
			}
		}

		vector<vector<int>> to_recurse;
		for (int i : v) {
			if (p[i] == i) {
				to_recurse.push_back(c[i]);
			}
		}

		vector<int> children;
		for (auto &rec : to_recurse) {
			children.push_back(self(rec, self));
		}

		int parent = vertices++;
		cost.push_back(max_sal);
		for (int child : children) {
			edges.emplace_back(child, parent);
		}
		return parent;
	};

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);

	int root = recurse(ind, recurse);

	cout << vertices << '\n';
	for (auto &x : cost) cout << x << ' '; cout << '\n';

	cout << root + 1 << '\n';
	for (auto &[u, v] : edges) cout << u + 1 << ' ' << v + 1 << '\n';
	return 0;
}