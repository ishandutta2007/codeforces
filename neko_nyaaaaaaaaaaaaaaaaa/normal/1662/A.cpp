#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> ans(11);
	while (n--) {
		int b, d; cin >> b >> d;
		ans[d] = max(ans[d], b);
	}

	for (int i = 1; i <= 10; i++) {
		if (ans[i] == 0) {
			cout << "MOREPROBLEMS\n";
			return;
		}
	}

	cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}