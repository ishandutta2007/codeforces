#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	set<char> seen; int ans = 0;
	for (char c: s) {
		if (seen.count(c)) {
			seen.clear(); ans += 2;
		} else {
			seen.insert(c);
		}
	}
	cout << s.size() - ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}