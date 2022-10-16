#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool luck(ll h, ll m) {
	if (h % 10 == 7) return 1;
	h /= 10;
	if (h % 10 == 7) return 1;
	if (m % 10 == 7) return 1;
	m /= 10;
	if (m % 10 == 7) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	
	ll x, h, m;
	cin >> x >> h >> m;
	ll ans = 0;
	for (ans = 0; ans <= 15000; ans++) {
		if (luck(h, m)) {cout << ans; return 0;}
		m -= x;
		if (m < 0) {
			m += 60;
			h--;
		}
		if (h < 0) {
			h = 23;
		}
	}
	
	return 0;
}