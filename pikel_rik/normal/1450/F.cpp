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

		vector<int> a(n), freq(n);
		for (auto &x : a) cin >> x, freq[--x]++;

		if (*max_element(freq.begin(), freq.end()) > (n + 1) / 2) {
			cout << "-1\n";
			continue;
		}

		vector<int> cnt(n);
		for (int i = 1; i < n; i++) {
			cnt[a[i]] += a[i] == a[i - 1];
		}

		int sum = accumulate(cnt.begin(), cnt.end(), 0);
		int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();

		if (2 * cnt[mx] > sum) {
			int ans = 2 * (sum - cnt[mx]) + 2 * (2 * cnt[mx] - sum);
			if (a[0] != mx || a[n - 1] != mx) {
				ans -= 1;
			}
			if (a[0] != mx && a[n - 1] != mx && 2 * cnt[mx] - sum > 1) {
				ans -= 1;
			}
			cout << ans << '\n';
		} else {
			cout << sum << '\n';
		}
	}
	return 0;
}