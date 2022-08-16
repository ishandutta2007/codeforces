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

		long long sum = accumulate(a.begin(), a.end(), 0ll);

		if (2 * sum % n == 0) {
			long long k = 2 * sum / n;
			map<int, int> mp;

			long long ans = 0;
			for (int i = 0; i < n; i++) {
				auto it = mp.find(k - a[i]);
				if (it != mp.end()) {
					ans += it->second;
				}
				mp[a[i]] += 1;
			}

			cout << ans << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}