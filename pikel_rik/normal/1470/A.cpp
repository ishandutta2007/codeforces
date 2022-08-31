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

		vector<int> a(n), c(m);
		for (auto &x : a) cin >> x, --x;
		for (auto &x : c) cin >> x;

		long long ans =0 ;
		for (auto x : a) {
			ans += c[x];
		}

		sort(a.begin(), a.end());
		for (int i = n - 1, j = 0; i >= 0 && j < m; i--) {
			if (c[a[i]] - c[j] > 0) {
				ans -= c[a[i]] - c[j++];
			}
		}

		cout << ans << '\n';
	}
	return 0;
}