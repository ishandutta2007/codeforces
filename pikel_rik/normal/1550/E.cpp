#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<vector<int>> pref(n, vector<int>(k + 1));
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			pref[i] = pref[i - 1];
		}
		if ('a' <= s[i] && s[i] < 'a' + k) {
			pref[i][s[i] - 'a'] += 1;
		} else {
			pref[i][k] += 1;
		}
	}

	auto f = [&](int len) -> bool {
		vector<vector<int>> possible(k, vector<int>(n, -1));
		for (int i = 0; i < k; i++) {
			for (int j = 0; j + len <= n; j++) {
				int c = pref[j + len - 1][i] + pref[j + len - 1][k];
				if (j != 0) {
					c -= pref[j - 1][i] + pref[j - 1][k];
				}
				if (c == len) {
					possible[i][j] = j;
				} else if (j != 0) {
					possible[i][j] = possible[i][j - 1];
				}
			}
			for (int j = n - len + 1; j < n; j++) {
				possible[i][j] = possible[i][j - 1];
			}
		}

		vector<int> dp(1 << k, -1);

		dp[0] = n + len - 1;
		for (int mask = 1; mask < (1 << k); mask++) {
			for (int i = 0; i < k; i++) {
				if ((mask >> i & 1) && dp[mask ^ (1 << i)] - len >= 0) {
					int pos = possible[i][dp[mask ^ (1 << i)] - len];
					dp[mask] = max(dp[mask], pos);
				}
			}
		}
		return dp.back() != -1;
	};

	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	cout << lo << '\n';
	return 0;
}