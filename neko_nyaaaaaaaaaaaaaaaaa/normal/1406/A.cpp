#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> cnt(102);
		while (n--) {
			int x; cin >> x;
			cnt[x]++;
		}

		int ans = 0;
		for (int i = 0; i <= 101; i++) {
			if (cnt[i] < 2) {
				ans += i; break;
			}
		} 
		for (int i = 0; i <= 101; i++) {
			if (cnt[i] < 1) {
				ans += i; break;
			}
		} 
		cout << ans << '\n';
	}

	return 0;
}