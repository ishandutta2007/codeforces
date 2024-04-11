#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll l, r, x, y, ans = 0;
	cin >> l >> r >> x >> y;
	
	if (y % x) {cout << 0; return 0;}
	
	ll n = y/x, k = sqrt(n);
	for (ll i = 1; i <= k; i++) {
		if (n % i != 0) continue;
		ll a = i, b = n/i;
		
		if (__gcd(a, b) != 1) continue;
		if (a*x <= r && b*x <= r && b*x >= l && a*x >= l) {
			ans++;
			if (b != i) ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}