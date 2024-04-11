#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool ok(ll n, ll a) {
	ll b = (a * a - 1) / 2;
	return a * a - b <= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		if (!ok(n, 3)) {
			cout << "0\n";
			continue;
		}
		ll l = 1, r = 25000;
		while(l < r) {
			ll mid = (l + r + 1) / 2;
			if (ok(n, 2 * mid + 1)) l = mid;
			else r = mid - 1;
		}
		cout << l << "\n";
	}
	return 0;
}