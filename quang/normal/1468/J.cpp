#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int p[N];

int root(int x) {
	return (p[x] == x ? x : p[x] = root(p[x]));
}

bool merge(int u, int v) {
	u = root(u);
	v = root(v);
	if (u != v) {
		p[u] = v;
		return true;
	}
	return false;
}

struct Edge {
	int u, v, c;
	Edge() {}
	Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<Edge> ed(m);
		vector<int> costs;

		for (auto &e : ed) {
			cin >> e.u >> e.v >> e.c;
			costs.push_back(e.c);
		}

		sort(ed.begin(), ed.end(), [&](Edge &lhs, Edge &rhs) {
			return lhs.c < rhs.c;
		});

		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}

		vector<int> costTree;

		for (auto e : ed) {
			if (merge(e.u, e.v)) {
				costTree.push_back(e.c);
			}
		}

		long long ans = 0;

		if (costTree.back() <= k) {
			ans = 1e18;
			for (auto e : ed) {
				ans = min(ans, (long long) abs(k - e.c));
			}
		} else {
			ans = 0;
			for (auto e : costTree) {
				if (e > k) ans += e - k;
			}
		}

		cout << ans << '\n';

	}

	return 0;
}