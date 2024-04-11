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

		vector<int> r(n);
		for (auto &i : r) cin >> i;

		int m;
		cin >> m;

		vector<int> b(m);
		for (auto &i : b) cin >> i;

		int ans = 0, sum_r = 0;
		for (int i = 0; i < n; i++) {
			int sum_b = 0;
			sum_r += r[i];
			ans = max(ans, sum_r);
			for (int j = 0; j < m; j++) {
				sum_b += b[j];
				ans = max({ans, sum_b, sum_r + sum_b});
			}
		}
		cout << ans << '\n';
	}
	return 0;
}