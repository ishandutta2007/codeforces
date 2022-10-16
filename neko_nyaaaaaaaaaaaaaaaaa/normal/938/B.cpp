#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, x;
	cin >> n;
	vector<ll> a(n+2);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 1;
	a[n+1] = 1000000;
	ll ans = a[n+1];
	for (ll i = 1; i <= n+1; i++) {
		ll t = max(1000000 - a[i], a[i-1] - 1);
		ans = min(ans, t);
	}
	cout << ans;
	
	return 0;
}