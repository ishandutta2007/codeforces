#include <bits/stdc++.h>
using namespace std;

bool match(string s, int msk) {
	for (int i = 0; i < 10; i++) {
		if (s[i] == '?') continue;
		else if ((s[i] - '0') != ((msk >> i) & 1)) return 0;
	}
	return 1;
}

void solve() {
	string s; cin >> s;
	int ans = 10;
	for (int ms = 0; ms < 1024; ms++) {
		if (!match(s, ms)) continue;

		int as = 0, bs = 0;
		int ap = 5, bp = 5;
		for (int i = 0; i < 10; i++) {
			if ((i % 2) == 0) ap--;
			else bp--;

			if (ms & (1 << i)) {
				if ((i % 2) == 0) as++;
				else bs++;
			}

			// game ended?
			if ((bs+bp < as) || (as+ap) < bs) {
				ans = min(ans, i+1);
				break;
			}
		}
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