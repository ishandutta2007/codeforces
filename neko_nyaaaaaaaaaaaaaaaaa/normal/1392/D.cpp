#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) {
			pos = i; break;
		}
	}
	rotate(s.begin(), s.begin()+pos, s.end());

	vector<int> gf;
	char prv = 'a'; int cnt = 0;
	for (char c: s) {
		if (c == prv) {
			cnt++;
		} else {
			if (cnt > 0) gf.push_back(cnt);
			cnt = 1;
			prv = c;
		}
	}
	if (gf.empty()) {
		// singular char
		cout << 1 + (n-1)/3 << endl;
	} else {
		gf.push_back(cnt);

		int ans = 0;
		for (int i: gf) {
			ans += i/3;
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}