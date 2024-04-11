#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	int sum = 0;
	while (n--) {
		int x; cin >> x;
		sum += x-1;
	}
	if (sum % 2) cout << "errorgorn\n";
	else cout << "maomao90\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}