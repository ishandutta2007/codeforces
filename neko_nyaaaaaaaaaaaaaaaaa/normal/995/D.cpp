#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	
	ll n, r;
	cin >> n >> r;
	
	n = 1 << n;
	
	vector<ll> a(n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	
	cout << s*1.0/n << '\n';
	
	while (r--) {
		ll x, y;
		cin >> x >> y;
		s -= a[x];
		s += y;
		a[x] = y;
		cout << s*1.0/n << '\n';
	}
	
	return 0;
}