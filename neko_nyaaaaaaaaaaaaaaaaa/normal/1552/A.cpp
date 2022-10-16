#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		string ss = s; sort(ss.begin(), ss.end());
		int ans = n;
		for (int i = 0; i < n; i++) {
			ans -= (ss[i] == s[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}