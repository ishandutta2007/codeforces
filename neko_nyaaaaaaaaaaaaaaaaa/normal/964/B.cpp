#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, a, b, c, t;
	cin >> n >> a >> b >> c >> t;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	if (b >= c) {
		cout << a*n; return 0;
	} else {
		ll delta = c-b;
		ll ans = a*n;
		for (int i = 0; i < n; i++) {
			ans += (t-v[i])*delta;
		}
		cout << ans;
	}
	
	return 0;
}