#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1e9;
	for (int r = 0; r < n; ++r) {
		int sum = 0;
		for (int k = 0; k <= r; ++k)
			sum += a[k];
		int thickness = r + 1;
		bool ok = true;
		for (int k = r + 1; k < n; ++k) {
			int rsum = 0, rk = k;
			while (rk < n && rsum < sum) {
				rsum += a[rk];
				rk++;
			}
			if (rsum != sum) {
				ok = false;
				break;
			}
			thickness = max(thickness, rk - k);
			k = rk - 1;
		}
		if (ok) ans = min(ans, thickness);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}