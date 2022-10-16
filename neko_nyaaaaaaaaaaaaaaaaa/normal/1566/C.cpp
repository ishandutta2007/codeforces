#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector<bool> used(n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			ans += 2;
		} else {
			if (s[i] == '0') {
				ans++;
			} else {
				bool ok = 0;
				if (i > 0 && !used[i-1] && (s[i-1] == '0' && t[i-1] == '0')) {
					ok = 1; used[i-1] = 1; 
				} else if (i+1 < n && !used[i+1] && (s[i+1] == '0' && t[i+1] == '0')) {
					ok = 1; used[i+1] = 1;
				}
				ans += ok;
			}
		}

		//cout << ans << ' ';
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