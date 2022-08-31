#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

namespace euc {
	template<typename T>
	tuple<T, ll, ll> extEuclid(T a, T b) {
		if (b == 0) {
			return make_tuple(a, 1, 0);
		}
		auto[g, x, y] = extEuclid(b, a % b);
		return make_tuple(g, y, x - y * (a / b));
	}

	template<typename T>
	T gcd(T a, T b) {
		return get<0>(extEuclid(a, b));
	}

	template<typename T>
	T modInverse(T a, T m) {
		auto[g, x, y] = extEuclid(a, m);
		if (g != 1) {
			return -1;
		} else {
			return (x % m + m) % m;
		}
	}

	ll CRT(ll a1, ll n1, ll a2, ll n2) {
		auto [g, m1, m2] = extEuclid(n1, n2);
		if (g != 1) {
			return -1;
		} else {
			ll x = (a1 * m2 * n2 + a2 * m1 * n1) % (n1 * n2);
			return x < 0 ? x + n1 * n2 : x;
		}
	}

	ll CRT(vector<ll> a, vector<ll> n) {
		ll x = CRT(a[0], n[0], a[1], n[1]), N = n[0] * n[1];
		for (int i = 2; i < n.size(); i++) {
			x = CRT(x, N, a[i], n[i]);
			N *= n[i];
		}
		return x;
	}
}

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

const int N = 1e6 + 10;
vector<int> cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b, p, x;
	cin >> a >> b >> p >> x;
	mod = p;

	ll pw = 1;
	for (int i = 0; i < p - 1; i++) {
		cnt[pw].push_back(i);
		pw = pw * a % p;
	}

	ll ans = 0, pp = p * p - p;
	for (int i = 1; i < p; i++) {
		ll tar = b * modinv(i) % mod;
		for (int j : cnt[tar]) {
			ll crt = euc::CRT(j, p - 1, i, p);
			if (crt <= x) {
				ans += (x - crt) / pp + 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}