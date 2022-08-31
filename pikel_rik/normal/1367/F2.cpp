#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> b = a;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		int sz = (int) b.size();

		for (auto &x : a) {
			x = lower_bound(b.begin(), b.end(), x) - b.begin();
		}

		vector<vector<int>> pos(n);
		for (int i = 0; i < n; i++) {
			pos[a[i]].push_back(i);
		}

		vector<int> dp(n);

		int ans = 1;
		for (int x = sz - 1; x >= 0; x--) {
			for (int i = 0; i < (int) pos[x].size(); i++) {
				int j = pos[x][i];
				if (x == sz - 1) {
					dp[j] = 0;
				} else {
					if (pos[x + 1][0] < j) {
						dp[j] = pos[x + 1].end() - lower_bound(pos[x + 1].begin(), pos[x + 1].end(), j);
					} else {
						dp[j] = (int) pos[x + 1].size() + dp[pos[x + 1].back()];
					}
				}
				ans = max(ans, i + 1 + dp[j]);
			}
		}

		cout << n - ans << '\n';
	}
	return 0;
}