#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> edges(n - 1);
	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(i);
		g[v].push_back(i);
		edges[i] = make_pair(u, v);
	}

	cout << "? " << n << ' ';
	for (int i = 1; i <= n; i++) {
		cout << i << ' ';
	}
	cout << endl;

	int mx;
	cin >> mx;

	vector<int> remaining(n - 1);
	iota(remaining.begin(), remaining.end(), 0);

	vector<bool> visited(n);
	while (remaining.size() > 1) {
		vector<int> query;
		fill(visited.begin(), visited.end(), false);

		auto dfs = [&](int u, int p, const auto &self) -> void {
			visited[u] = true;
			for (int i : g[u]) {
				int v = edges[i].first ^ edges[i].second ^ u;
				if (v != p && 2 * query.size() < remaining.size()) {
					query.push_back(i);
					self(v, u, self);
				}
			}
		};

		vector<int> vertices;

		for (int i : remaining) {
			vertices.push_back(edges[i].first);
			vertices.push_back(edges[i].second);
		}

		for (int u : vertices) {
			if (!visited[u] && 2 * query.size() < remaining.size()) {
				dfs(u, -1, dfs);
			}
		}

		vector<int> actual_query;
		for (int i : query) {
			auto [u, v] = edges[i];
			actual_query.push_back(u);
			actual_query.push_back(v);
		}

		sort(actual_query.begin(), actual_query.end());
		actual_query.erase(unique(actual_query.begin(), actual_query.end()), actual_query.end());

		cout << "? " << actual_query.size() << ' ';
		for (int u : actual_query) {
			cout << u + 1 << ' ';
		}
		cout << endl;

		int ans;
		cin >> ans;

		sort(query.begin(), query.end());
		if (ans == mx) {
			vector<int> remove(remaining.size() - query.size());
			set_difference(remaining.begin(), remaining.end(), query.begin(), query.end(), remove.begin());
			for (int i : remove) {
				auto [u, v] = edges[i];
				g[u].erase(find(g[u].begin(), g[u].end(), i));
				g[v].erase(find(g[v].begin(), g[v].end(), i));
			}
			remaining.swap(query);
		} else {
			for (int i : query) {
				auto [u, v] = edges[i];
				g[u].erase(find(g[u].begin(), g[u].end(), i));
				g[v].erase(find(g[v].begin(), g[v].end(), i));
			}
			vector<int> new_remaining(remaining.size() - query.size());
			set_difference(remaining.begin(), remaining.end(), query.begin(), query.end(), new_remaining.begin());
			remaining.swap(new_remaining);
		}
	}

	int i = remaining.front();
	auto [u, v] = edges[i];
	cout << "! " << u + 1 << ' ' << v + 1 << endl;
	return 0;
}