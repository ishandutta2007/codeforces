#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s; cin >> s;
	reverse(s.begin(), s.end());

	map<char, int> cnt;
	for (char c: s) cnt[c]++;

	while (s.size()) {
		if (cnt[s.back()] == 1) break;
		cnt[s.back()]--;
		s.pop_back();
	}

	reverse(s.begin(), s.end());
	cout << s << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}