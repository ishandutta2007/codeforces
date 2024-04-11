#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p(n);
	for (auto &x : p) cin >> x;

	vector<vector<int>> ans(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		int mark = p[i];
		auto dfs = [&](int x, int y, const auto &self) -> void {
			ans[x][y] = mark, p[i] -= 1;
			if (p[i] > 0 && y > 0 && ans[x][y - 1] == -1) {
				self(x, y - 1, self);
			}
			if (p[i] > 0) {
				self(x + 1, y, self);
			}
		};
		dfs(i, i, dfs);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}