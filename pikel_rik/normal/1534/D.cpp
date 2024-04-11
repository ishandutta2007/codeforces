#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	auto query = [&](int r) -> vector<int> {
		cout << "? " << r + 1 << endl;
		vector<int> ans(n);
		for (auto &x : ans) cin >> x;
		return ans;
	};

	auto d = query(0);

	vector<bool> used(n);
	used[0] = true;

	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) {
			g[0].push_back(i);
			g[i].push_back(0);
			used[i] = true;
		}
	}

	for (int lvl = 1; lvl <= n; lvl++) {
		for (int v = 0; v < n; v++) {
			if (d[v] == lvl && !used[v]) {
				auto dv = query(v);
				used[v] = true;
				int p = -1;
				for (int i = 0; i < n; i++) {
					if (dv[i] == 1) {
						if (used[i]) {
							p = i;
						} else {
							g[v].push_back(i);
							g[i].push_back(v);
							used[i] = true;
						}
					}
				}
				g[p].push_back(v);
				g[v].push_back(p);
				for (int i = 0; i < n; i++) {
					if (d[i] == lvl && dv[i] == 2) {
						g[p].push_back(i);
						g[i].push_back(p);
						used[i] = true;
					}
				}
			}
		}
	}

	cout << "!\n";
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			if (i < j) {
				cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
	}
	cout << endl;
	return 0;
}