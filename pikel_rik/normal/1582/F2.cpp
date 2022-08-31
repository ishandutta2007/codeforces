#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int mx = *max_element(a.begin(), a.end());
	int lg = 32 - __builtin_clz(mx | 1);

	vector<vector<bool>> visited(1 << lg, vector<bool>(mx + 1));
	vector<vector<int>> to_update(mx + 1);

	for (int i = 0; i <= mx; i++) {
		visited[0][i] = true;
		to_update[i].push_back(i);
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			continue;
		}
		for (int j : to_update[a[i]]) {
			for (int k = a[i]; k <= mx && !visited[j][k]; k++) {
				visited[j][k] = true;
				if (k + 1 <= mx && !visited[j ^ (k + 1)][k + 1]) {
					to_update[k + 1].push_back(j ^ (k + 1));
				}
			}
		}
		to_update[a[i]].clear();
	}

	vector<int> ans;
	for (int j = 0; j < (1 << lg); j++) {
		if (visited[j].back()) {
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