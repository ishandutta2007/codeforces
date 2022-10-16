#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	// bracket with k-1 singles, 1 all-fit
	int brac = n/2;
	string ans;
	for (int i = 1; i < k; i++) {
		ans += "()"; brac--;
	}
	while (brac > 0) {
		ans += '('; brac--;
	}
	while (ans.size() < s.size()) {
		ans += ')';
	}

	vector<pair<int, int>> res;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (s[j] == ans[i]) {
				// move j to i
				res.emplace_back(i+1, j+1);
				reverse(s.begin()+i, s.begin()+j+1);
				break;
			}
		}
	}

	cout << res.size() << '\n';
	for (auto [u, v]: res) cout << u << ' ' << v << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}