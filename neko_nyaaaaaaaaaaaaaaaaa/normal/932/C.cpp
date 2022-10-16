/** neko_nyaa's very long and elaborated template **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, a, b;
	cin >> n >> a >> b;
	ll x = -1, y = -1;
	for (ll i = 0; i*a <= n; i++) {
	/*	bool flag = 0;
		for (ll j = 0; j <= n; j++) {
			if ((i*a + j*b) == n) {x = i; y = j; flag = 1; break;}
		}
		if (flag) break;	*/
		ll tmp = n - i*a;
		if (tmp % b == 0) {
			x = i;
			y = tmp/b;
			break;
		}
	}
	if (x == -1) {cout << x; return 0;}
	ll pt = 1;
	for (ll i = 0; i < x; i++) {
		for (ll j = 1; j < a; j++) {
			cout << pt+j << " ";
		}
		cout << pt << " ";
		pt += a;
	}
	for (ll i = 0; i < y; i++) {
		for (ll j = 1; j < b; j++) {
			cout << pt+j << " ";
		}
		cout << pt << " ";
		pt += b;
	}
	
	return 0;
}