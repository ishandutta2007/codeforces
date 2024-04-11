#include <bits/stdc++.h>
using namespace std;

#define int long long

bool ok(int x, int y, int a, int b, int k) {
	x -= k*a, y -= k*a;
	if (x < 0 || y < 0) return 0;
	if (a == b) return 1;
	int lf = x/(b-a) + y/(b-a);

	return lf >= k;
} 

void solve() {
	int x, y, a, b; cin >> x >> y >> a >> b;
	if (x > y) swap(x, y);
	if (a > b) swap(a, b);
	
	int lo = 0, hi = 1000000000;
	while (lo < hi) {
		int mid = (lo + hi + 1)/2;

		if (ok(x, y, a, b, mid)) {
			lo = mid;
		} else {
			hi = mid-1;
		}
	}
	cout << lo << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}