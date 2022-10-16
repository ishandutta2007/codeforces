#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m;
	cin >> n;
	map<ll, ll> a;
	while (n--) {
		ll x, y;
		cin >> x >> y;
		a[x] = max(a[x], y);
	}
	cin >> m;
	while (m--) {
		ll x, y;
		cin >> x >> y;
		a[x] = max(a[x], y);
	}
	
	ll ans = 0;
	for (auto it = a.begin(); it != a.end(); it++) {
		ans += it->second;
	}
	cout << ans;
	
	return 0;
}