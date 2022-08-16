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

		map<int, long long> mp;

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long long)(n - i) * mp[a[i]];
			mp[a[i]] += i + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}