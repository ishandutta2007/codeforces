#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int n) {
	int ans = 0;
	while (n) {
		ans += n; n /= 10;
	}
	return ans;
}

void solve() {
	int l, r; cin >> l >> r;
	cout << f(r) - f(l) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}