#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> p(n);
		for (auto &x : p) cin >> x;

		long long ans = 0, sum = 0;
		for (int i = 1; i < n; i++) {
			//p[i] / (p[0] + sum) <= k / 100
			//p[i] * 100 <= k * (p[0] + sum)
			//p[i] * 100 - k * sum <= k * p[0]
			//p[0] >= (p[i] * 100 - k * sum + k - 1) / k
			ans = max(ans, (p[i] * 100ll - k * sum + k - 1) / k);
			sum += p[i];
		}

		cout << max(0ll, ans - p[0]) << '\n';
	}
	return 0;
}