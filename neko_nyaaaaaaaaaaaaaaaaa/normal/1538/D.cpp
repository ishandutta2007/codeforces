#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, k; cin >> a >> b >> k;

	if (k == 1) {
		int g = __gcd(a, b);

		if (g == a && g == b) cout << "NO\n";
		else if (g != a && g != b) cout << "NO\n";
		else cout << "YES\n";

		return;
	}

	while (a % 2 == 0) {
		k--; a /= 2;
	}
	for (int i = 3; i*i <= a; i += 2) {
		while (a % i == 0) {
			k--; a /= i;
		}
	}
	if (a > 1) k--;

	while (b % 2 == 0) {
		k--; b /= 2;
	}
	for (int i = 3; i*i <= b; i += 2) {
		while (b % i == 0) {
			k--; b /= i;
		}
	}
	if (b > 1) k--;

	if (k <= 0) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}