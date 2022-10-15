#include <iostream>

using namespace std;

typedef long long ll;

void lol() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	bool ok = true;
	if (x1 == x2 && a+b != 0) ok = false;
	ll m = min(a,b); a -= m; b -= m;
	if (y1 == y2 && c+d != 0) ok = false;
	m = min(c,d); c -= m; d -= m;
	if (x-a < x1 || x+b > x2) ok = false;
	if (y-c < y1 || y+d > y2) ok = false;
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}