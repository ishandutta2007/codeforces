#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> cnt(30);

	long long ans = 0;
	while (n--) {
		int x; cin >> x;

		int msb = 0;
		for (int j = 29; j >= 0; j--) {
			if (x & (1 << j)) {
				msb = j; break;
			}
		}

		ans += cnt[msb]; cnt[msb]++;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}