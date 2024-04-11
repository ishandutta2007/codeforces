#include <iostream>

using namespace std;

typedef long long ll;

int a, b, q;
int c;
ll ss[44444];

ll calc(ll x) {
	if (x == 0) return 0;
	ll u = 0;
	u += ss[x%(a*b)];
	x -= x%(a*b);
	u += ((x+1)/(a*b))*c;
	return u;
}

void lol() {
	cin >> a >> b >> q;
	c = 0;
	for (int i = 0; i < a*b; i++) {
		if ((i%a)%b != (i%b)%a) c++;
		ss[i] = c;
	}
	for (int i = 1; i <= q; i++) {
		ll x, y;
		cin >> x >> y;
		cout << calc(y)-calc(x-1) << " ";
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}