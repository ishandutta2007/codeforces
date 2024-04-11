#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// 1 --> definitely push new item
	// how to tell when to pop?

	vector<int> ans;
	for (int i: a) {
		if (i == 1) {
			ans.push_back(1);
		} else {
			while (i-1 != ans.back()) {
				ans.pop_back();
			}
			ans.pop_back();
			ans.push_back(i);
		}
		for (int j = 0; j < ans.size(); j++) {
			cout << ans[j];
			if (j+1 == ans.size()) cout << '\n';
			else cout << '.';
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