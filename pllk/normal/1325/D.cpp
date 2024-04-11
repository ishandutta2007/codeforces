#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll u, v;
	cin >> u >> v;
	if (u == 0 && v == 0) {
		cout << "0\n";
		return 0;
	}
	if (u == v) {
		cout << "1\n";
		cout << u << "\n";
		return 0;
	}
	if (u%2 != v%2 || u > v) {
		cout << "-1\n";
		return 0;
	}
	ll v2 = v-u;
	ll a = 0;
	for (int b = 61; b >= 0; b--) {
		ll x = 1LL<<b;
		if (u&x) continue;
		if (v2 >= 2*x) {
			v2 -= 2*x;
			a |= x;
		}
	}
	if (v2 == 0) {
		cout << "2\n";
		cout << (u|a) << " " << a << "\n";
	} else {
		cout << "3\n";
		ll b = (v-u)/2;
		cout << u << " " << b << " " << b << "\n";
	}
}