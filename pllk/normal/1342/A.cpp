#include <iostream>

using namespace std;

typedef long long ll;

void lol() {
	ll x, y;
	cin >> x >> y;
	ll a, b;
	cin >> a >> b;
	ll c = 0;
	if (x <= 0 && y <= 0) {x = -x; y = -y;}
	if (x >= 0 && y >= 0) {
		ll u = min(x,y);
		c += u*min(2*a,b);
		x -= u; y -= u;
		c += max(x,y)*a;
	} else {
		c += abs(x)*a;
		c += abs(y)*a;
	}
	cout << c << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}