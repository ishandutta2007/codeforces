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

		int mxk, len_sum = 0;
		for (int i = 1;; i++) {
			len_sum += i;
			if (len_sum > n) {
				mxk = i - 1;
				break;
			}
		}

		vector<long long> dp(n), new_dp(n);
		partial_sum(a.rbegin(), a.rend(), dp.rbegin(), [](auto x, auto y) { return x > y ? x : y; });

		len_sum = 0;

		int k;
		for (k = 2; k <= mxk; k++) {
			fill(new_dp.begin(), new_dp.end(), LLONG_MIN);

			len_sum += k - 1;
			long long sum = accumulate(a.begin(), a.begin() + k, 0ll);

			for (int i = k - 1; i + len_sum < n; i++) {
				if (sum < dp[i + 1]) {
					new_dp[i - k + 1] = sum;
				}
				sum -= a[i - k + 1];
				sum += a[i + 1];
			}

			dp.swap(new_dp);
			partial_sum(dp.rbegin(), dp.rend(), dp.rbegin(), [](auto x, auto y) { return x > y ? x : y; });

			if (dp[0] == LLONG_MIN) {
				break;
			}
		}

		k -= 1;
		cout << k << '\n';
	}
	return 0;
}