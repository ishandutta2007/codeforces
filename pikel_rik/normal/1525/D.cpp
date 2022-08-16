#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> next(n + 1, n);
	for (int i = n - 1; i >= 0; i--) {
		if (!a[i]) next[i] = i;
		else next[i] = next[i + 1];
	}

	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		if (!a[i]) {
			continue;
		}
		vector<int> new_dp(n, INT_MAX);
		int pref_mn = INT_MAX;
		if (count(dp.begin(), dp.end(), 0) == n && !a[0]) {
			new_dp[0] = i;
		}
		for (int j = 0; j < n; j++) {
			pref_mn = min(pref_mn, dp[j]);
			if (pref_mn != INT_MAX && next[j + 1] != n) {
				new_dp[next[j + 1]] = min(new_dp[next[j + 1]], abs(i - next[j + 1]) + pref_mn);
			}
		}
		dp.swap(new_dp);
	}
	cout << *min_element(dp.begin(), dp.end()) << '\n';
	return 0;
}