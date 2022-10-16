#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i] %= 2;
	}
	vector<int> onepos;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) onepos.push_back(i);
	}

	int ans = 1000000000000000000LL;
	// 010101
	{
		int nd = n/2;
		if (onepos.size() == nd) {
			int tmp = 0;
			for (int i = 1, j = 0; i < n; i += 2, j++) {
				tmp += abs(onepos[j] - i);
			}
			ans = min(ans, tmp);
		}
	}

	// 101010
	{
		int nd = (n+1)/2;
		if (onepos.size() == nd) {
			int tmp = 0;
			for (int i = 0, j = 0; i < n; i += 2, j++) {
				tmp += abs(onepos[j] - i);
			}
			ans = min(ans, tmp);
		}
	}

	if (ans == 1000000000000000000LL) {
		cout << "-1\n";
	} else {
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