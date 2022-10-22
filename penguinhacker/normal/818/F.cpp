#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool ok(ll n, ll e) {
	ll half = (e + 1) / 2;
	if (half > n - 1) return 0;
	n -= half;
	return n * (n - 1) / 2 >= e / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll l = n - 1, r = 2 * (n - 1);
		while(l < r) {
			ll mid = (l + r + 1) / 2;
			if (ok(n, mid)) l = mid;
			else r = mid - 1;
		}
		cout << l << "\n";
	}
	return 0;
}