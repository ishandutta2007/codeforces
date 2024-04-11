#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int a[3]; cin >> a[0] >> a[1] >> a[2];
	int sum = a[0] + a[1]*2 + a[2]*3;
	int targ = sum/2;
	int x = 0, y = 0;

	for (int i = 2; i >= 0; i--) {
		int mn = min(a[i], targ/(i+1));
		a[i] -= mn;
		x += mn*(i+1);
		targ -= mn*(i+1);
	}

	y = sum - x;
	cout << abs(x-y) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}