#include <iostream>

using namespace std;

typedef long long ll;

ll calc(ll a, ll b) {
	if (a < b) swap(a,b);
	ll x = min(b,min(a-b,a/2));
	ll c = x;
	a -= 2*x;
	b -= x;
	ll u = min(a,b)/3*2;
	c += u;
	a -= u/2*3;
	b -= u/2*3;
	while (true) {
		if (a < b) swap(a,b);
		if (a >= 2 && b >= 1) {
			c++; a -= 2; b -= 1;
		} else break;
	}
	return c;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << calc(a,b) << "\n";
	}
}