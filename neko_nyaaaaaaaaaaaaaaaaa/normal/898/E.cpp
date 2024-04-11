#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n, x, m;
	ll count0 = 0, countsq = 0;
	cin >> n;
	m = n;
	vector<ll> a;
	while (n--) {
		cin >> x;
		if (x == 0) {count0++;}
		ll k = sqrt(x);
		a.push_back(min(abs(k*k - x), abs((k+1)*(k+1) - x)));
		if (k*k == x) {countsq++;}
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	if (countsq <= m/2) {
		for (ll i = 0; i < m/2; i++) {
			ans += a[i];
		}
	} else {
		ans = countsq - m/2;
		if (count0 > m/2) {
			ans += count0 - m/2;
		}
	}
	cout << ans;
	
	return 0;
}