#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, L, R;
	cin >> n >> m >> L >> R;

	int parity = ((ll)n * m) & 1;
	if (parity == 0) {
		int even, odd;
		if ((R - L) & 1) {
			even = (R - L + 1) / 2, odd = (R - L + 1) / 2;
		} else {
			even = (L % 2 == 0) + (R - L + 1) / 2, odd = R - L + 1 - even;
		}
		cout << (modexp(R - L + 1, n * m) + modexp(mod + odd - even, n * m)) * modinv(2) % mod << '\n';
	} else {
		cout << modexp(R - L + 1, n * m) << '\n';
	}
	return 0;
}