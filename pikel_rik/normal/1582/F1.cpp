#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	constexpr int MX = 500;

	vector<vector<bool>> visited(MX + 1, vector<bool>(1 << 10));
	for (int i = 0; i <= MX; i++) {
		visited[i][0] = true;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			continue;
		}
		for (int j = 0; j < (1 << 10); j++) {
			if (visited[a[i] - 1][j] && !visited[a[i]][j ^ a[i]]) {
				for (int k = a[i]; k <= MX && !visited[k][j ^ a[i]]; k++) {
					visited[k][j ^ a[i]] = true;
				}
			}
		}
	}

	vector<int> ans;
	for (int j = 0; j < (1 << 10); j++) {
		if (visited.back()[j]) {
			ans.push_back(j);
		}
	}

	cout << (int) ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}