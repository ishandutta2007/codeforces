#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto solve = [&](int n, int k, auto &&self) -> vector<vector<int>> {
		if (k > n - 1) {
			return vector<vector<int>>(n, vector<int>(n, 1));
		} else {
			vector<vector<int>> ans(n, vector<int>(n));

			auto child_ans = self((n + k - 1) / k, k, self);
			for (int u = 0; u < n; u++) {
				for (int v = u + 1; v < n; v++) {
					if (u / k == v / k) {
						ans[u][v] = 1;
					} else {
						ans[u][v] = 1 + child_ans[u / k][v / k];
					}
				}
			}

			return ans;
		}
	};

	int n, k;
	cin >> n >> k;

	auto ans = solve(n, k, solve);

	int max_colors = 0;
	for (int u = 0; u < n; u++) {
		for (int v = u + 1; v < n; v++) {
			max_colors = max(max_colors, ans[u][v]);
		}
	}

	cout << max_colors << '\n';
	for (int u = 0; u < n; u++) {
		for (int v = u + 1; v < n; v++) {
			cout << ans[u][v] << ' ';
		}
	}
	cout << '\n';
	return 0;
}