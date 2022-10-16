#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(0);
	
	ll p, y;
	cin >> p >> y;
	if (y == 2) {cout << -1; return 0;}
	if (y % 2 == 0) {y--;}
	for ( ; y > p; y -= 2) {
		ll k = sqrt(y);
		bool flag = 1;
		for (ll i = 3; i <= min(p, k); i += 2) {
			if (y % i == 0) {flag = 0; break;}
		}
		if (flag) {cout << y; return 0;}
	}
	cout << -1;
	
	return 0;
}