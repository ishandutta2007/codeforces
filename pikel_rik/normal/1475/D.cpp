#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(n);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;

		int ones = count(b.begin(), b.end(), 1);

		vector<long long> one(1), two(1);
		one.reserve(ones + 1), two.reserve(n - ones + 1);

		for (int i = 0; i < n; i++) {
			if (b[i] == 1) one.push_back(a[i]);
			else two.push_back(a[i]);
		}

		sort(one.begin() + 1, one.end(), greater<>());
		sort(two.begin() + 1, two.end(), greater<>());

		partial_sum(one.begin(), one.end(), one.begin());
		partial_sum(two.begin(), two.end(), two.begin());

		int ans = INT_MAX;
		for (int i = 0; i < int(one.size()); i++) {
			if (two.back() >= m - one[i]) {
				int idx = lower_bound(two.begin(), two.end(), m - one[i]) - two.begin();
				ans = min(ans, i + 2 * idx);
			}
		}
		cout << (ans == INT_MAX ? -1 : ans) << '\n';
	}
	return 0;
}