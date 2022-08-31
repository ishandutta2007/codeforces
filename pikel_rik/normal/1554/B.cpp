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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int lg = 32 - __builtin_clz(n);
		int mx = (1 << lg) - 1;

		long long ans = LLONG_MIN;
		for (int i = 0; i < n; i++) {
			int limit = k * mx / (i + 1); //i * x <= k * mx
			for (int diff = 1; i - diff >= 0 && diff <= limit; diff++) {
				ans = max(ans, (long long)(i + 1) * (i + 1 - diff) - k * (a[i] | a[i - diff]));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}