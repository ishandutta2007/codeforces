#define fast ios::sync_with_stdio(false); cin.tie(0)

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a, b, mod, x;
const int sz = 1e6 + 5;
ll d[sz];
ll cycSz = 1;

ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll ans = modpow(a, b >> 1);
	ans *= ans;
	ans %= mod;
	if (b & 1) {
		ans *= a; ans %= mod;
	}
	return ans;
}

void prec() {
	ll ainv = modpow(a, mod - 2), mul = b;
	while (true) {
		d[mul] = cycSz - 1;
		mul *= ainv;
		mul %= mod;
		if (mul == b)break;
		cycSz++;
	}
}

int main() {
	fast;
	cin >> a >> b >> mod >> x;
	prec();
	ll apw = a, tot = 0;
	for (ll i = 1; i <= mod; i++) {
		ll tmp = (i*apw) % mod;
		ll howMany = (x / mod) + (x%mod >= i);
		if (!howMany)break;
		if (tmp == b) {
			tot++;
			howMany--;
			tot += (howMany / cycSz);
		}
		else {
			if (d[tmp]) {
				howMany -= d[tmp];
				if (howMany > 0) {
					tot++;
					howMany--;
					tot += (howMany / cycSz);
				}
			}
		}
		apw *= a;
		apw %= mod;
	}
	cout << tot << endl;
	return 0;
}