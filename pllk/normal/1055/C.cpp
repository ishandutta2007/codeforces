#include <iostream>

using namespace std;

typedef long long ll;

ll la, ra, ta;
ll lb, rb, tb;
ll gg;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}

bool ok(ll x) {
	return lb-x*gg >= la;
}

ll calc() {
	ll c1 = max(la,lb);
	ll c2 = min(ra,rb);
	if (c2 < c1) return 0;
	return c2-c1+1;
}

int main() {
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	gg = gcd(ta,tb);
	if (la >= lb) {
		swap(la,lb);
		swap(ra,rb);
	}
	ll k = 0;
	for (ll b = 1e9; b >= 1; b /= 2) {
		while (ok(k+b)) k += b;
	}
	lb -= k*gg;
	rb -= k*gg;
	ll t1 = calc();
	lb -= gg;
	rb -= gg;
	ll t2 = calc();
	cout << max(t1,t2) << "\n";
}