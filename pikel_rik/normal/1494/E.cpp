#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	set<tuple<int, int, char>> edges;
	set<tuple<int, int, char, char>> both_edges;

	int same = 0;

	while (m--) {
		char c;
		cin >> c;

		if (c == '+') {
			int u, v; char col;
			cin >> u >> v >> col;
			edges.emplace(u, v, col);
			auto it = edges.lower_bound(make_tuple(v, u, 0));
			if (it != edges.end() && get<0>(*it) == v && get<1>(*it) == u) {
				both_edges.insert(make_tuple(min(u, v), max(u, v), col, get<2>(*it)));
				same += col == get<2>(*it);
			}
		} else if (c == '-') {
			int u, v;
			cin >> u >> v;
			auto it1 = edges.lower_bound(make_tuple(u, v, 0));
			auto it2 = both_edges.lower_bound(make_tuple(min(u, v), max(u, v), 0, 0));
			if (it2 != both_edges.end() && get<0>(*it2) == min(u, v) && get<1>(*it2) == max(u, v)) {
				same -= get<2>(*it2) == get<3>(*it2);
				both_edges.erase(it2);
			}
			edges.erase(it1);
		} else {
			int k;
			cin >> k;
			if (k % 2 != 0) {
				cout << (both_edges.empty() ? "NO" : "YES") << '\n';
			} else {
				cout << (same > 0 ? "YES" : "NO") << '\n';
			}
		}
	}
	return 0;
}