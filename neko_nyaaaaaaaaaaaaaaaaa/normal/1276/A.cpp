#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

void solve() {
	string s; cin >> s;
	// remove "twone" first, then "two" and "one"
	// remove middle character every time

	int n = s.size();
	vector<int> remov(n);

	for (int i = 4; i < n; i++) {
		if (s.substr(i-4, 5) == "twone") {
			remov[i-2] = 1;
		}
	}

	for (int i = 2; i < n; i++) {
		if (remov[i] || remov[i-1] || remov[i-2]) continue;

		if (s.substr(i-2, 3) == "two" || s.substr(i-2, 3) == "one") {
			remov[i-1] = 1;
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (remov[i]) ans.push_back(i+1);
	}

	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
		cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}