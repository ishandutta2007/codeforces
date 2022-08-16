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
		for (int i = 0; i < n; i++) {
			cin >> a[i], a[i] -= i;
		}

		long long ans = 0;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			ans += mp[a[i]]++;
		}
		cout << ans << '\n';
	}
	return 0;
}