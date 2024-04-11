#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	array<int, 4> n;
	for (int i = 0; i < 4; i++) cin >> n[i];

	array<vector<int>, 4> a;
	array<vector<vector<int>>, 4> g;

	for (int i = 0; i < 4; i++) {
		a[i].resize(n[i]), g[i].resize(n[i]);
		for (auto &x : a[i]) cin >> x;
	}

	for (int i = 0, m; i < 3; i++) {
		cin >> m;
		for (int j = 0, x, y; j < m; j++) {
			cin >> x >> y, --x, --y;
			g[i][x].push_back(y);
		}
	}

	vector<int> dp0 = a[3], dp1;
	for (int d = 2; d >= 0; d--) {
		dp1.assign(n[d], -1);
		vector<int> ind(n[d + 1]);
		iota(ind.begin(), ind.end(), 0);
		ind.erase(remove_if(ind.begin(), ind.end(), [&](int i) {
			return dp0[i] == -1;
		}), ind.end());

		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return dp0[i] < dp0[j];
		});

		vector<bool> mark(n[d + 1]);
		for (int i = 0; i < n[d]; i++) {
			for (int j : g[d][i]) {
				mark[j] = true;
			}
			int choice = -1;
			for (int j : ind) {
				if (!mark[j]) {
					choice = j;
					break;
				}
			}
			if (choice != -1) {
				dp1[i] = a[d][i] + dp0[choice];
			}
			for (int j : g[d][i]) {
				mark[j] = false;
			}
		}
		dp0.swap(dp1);
	}

	int ans = INT_MAX;
	for (int i = 0; i < n[0]; i++) {
		if (dp0[i] != -1) {
			ans = min(ans, dp0[i]);
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
	return 0;
}