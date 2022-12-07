#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s, t; cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	map<char, int> mp;
	for (char c: t) mp[c]++;

	string rs;
	for (char c: s) {
		if (mp[c] > 0) {
			mp[c]--;
			rs.push_back(c);
		}
	}

	if (t == rs) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}