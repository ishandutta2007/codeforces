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

		vector<int> d(n);
		for (auto &x : d) cin >> x;

		sort(d.begin(), d.end());

		long long ans = d.back(), sum = 0;
		for (int i = 1; i < n; i++) {
			ans += sum - (long long)i * d[i];
			sum += d[i];
		}
		cout << ans << '\n';
	}
	return 0;
}