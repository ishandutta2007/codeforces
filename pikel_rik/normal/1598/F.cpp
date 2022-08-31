#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int sum_len = 0;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum_len += s[i].length();
	}

	vector<int> mn(n), sum(n);
	vector<vector<int>> cnt(n, vector<int>(sum_len + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int) s[i].length(); j++) {
			if (s[i][j] == '(') {
				sum[i] += 1;
			} else {
				sum[i] -= 1;
			}
			mn[i] = min(mn[i], sum[i]);
			if (sum[i] == mn[i]) {
				cnt[i][-sum[i]] += 1;
			}
		}
	}

	vector<int> balance(1 << n);
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) {
				balance[mask] += sum[i];
			}
		}
	}

	vector<int> dp(1 << n), dp_balanced(1 << n, -1); dp_balanced[0] = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if ((mask >> i & 1) && dp_balanced[mask ^ (1 << i)] != -1) {
				auto child_mask = mask ^ (1 << i);
				dp[mask] = max(dp[mask], dp_balanced[child_mask] + cnt[i][balance[child_mask]]);
				if (balance[child_mask] + mn[i] >= 0) {
					dp_balanced[mask] = max(dp_balanced[mask], dp_balanced[child_mask] + cnt[i][balance[child_mask]]);
				}
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
	return 0;
}