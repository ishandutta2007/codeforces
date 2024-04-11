#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s; cin >> s; int n = s.size();
	vector<int> pref(n+1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + (s[i-1] - '0');
	}

	int w, q; cin >> w >> q;

	vector<vector<int>> pos(9);
	for (int i = w; i <= n; i++) {
		int sumdig = pref[i] - pref[i-w];
		pos[sumdig % 9].push_back(i-w);
	}

	while (q--) {
		int l, r, k; cin >> l >> r >> k;

		pair<int, int> ans = {n, n};
		int v = (pref[r] - pref[l-1]) % 9;

		for (int a = 0; a < 9; a++) {
			for (int b = 0; b < 9; b++) {
				if (pos[a].empty()) continue;
				if (pos[b].empty()) continue;
				if (a == b && pos[a].size() < 2) continue;

				int val = (a*v + b) % 9;
				if (val == k) {
					if (a == b) {
						ans = min(ans, make_pair(pos[a][0], pos[a][1]));
					} else {
						ans = min(ans, make_pair(pos[a][0], pos[b][0]));
					}
				}
			}
		}

		if (ans.first >= n) {
			cout << "-1 -1\n";
		} else {
			cout << ans.first+1 << ' ' << ans.second+1 << '\n';
		}
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