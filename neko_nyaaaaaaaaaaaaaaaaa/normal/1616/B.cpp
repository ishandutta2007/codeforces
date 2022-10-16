#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	string ans1;
	ans1.push_back(s[0]);
	ans1.push_back(s[0]);

	int k = n;
	for (int i = 0; i < n; i++) {
		if (s[i] < s[i+1]) {
			k = i+1; break;
		}
	}

	string ans2;
	for (int i = 0; i < k; i++) {
		ans2.push_back(s[i]);
	}
	for (int i = k-1; i >= 0; i--) {
		ans2.push_back(s[i]);
	}

	cout << min(ans1, ans2) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}