#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll calc(ll b, ll k) {
	if (b == 1) return 0;
	ll a = b/4;
	ll u = calc(a,k%a);
	if (k/a == 0) u += 0;
	if (k/a == 1) u += 2*a;
	if (k/a == 2) u += 3*a;
	if (k/a == 3) u += a;
	return u;
}

vector<ll> calc2(ll k) {
	ll u = 1;
	while (true) {
		if (k < u) {
			ll x = calc(u,k);
			ll a = u+k;
			ll b = 2*u+x;
			ll c = a^b;
			return {a,b,c};
		} else {
			k -= u;
			u *= 4;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		n--;
		if (n%3 == 0) {
			auto u = calc2(n/3);
			cout << u[0] << "\n";
		} else if (n%3 == 1) {
			auto u = calc2((n-1)/3);
			cout << u[1] << "\n";
		} else {
			auto u = calc2((n-2)/3);
			cout << u[2] << "\n";
		}
	}
}