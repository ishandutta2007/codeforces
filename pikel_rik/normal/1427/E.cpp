#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

namespace euclidean {
    template<typename T>
    tuple<T, T, T> extEuclid(T a, T b) {
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
}

using namespace euclidean;

vector<tuple<int, ll, ll>> ans;

ll multiple(ll x, ll n) {
	vector<ll> pows = {x};
	for (int i = 1; (1ll << i) <= n; i++) {
		ans.emplace_back(1, pows.back(), pows.back());
		pows.push_back(2 * pows.back());
	}

	int low_bit = 64 - __builtin_clzll(n & -n) - 1;
	ll cur = pows[low_bit];

	for (int i = low_bit + 1; (1ll << i) <= n; i++) {
		if (n & (1ll << i)) {
			ans.emplace_back(1, cur, pows[i]);
			cur += pows[i];
		}
	}
	return cur;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x;
	cin >> x;

	int high_bit = 64 - __builtin_clzll(x) - 1;

	ll y = multiple(x, 1ll << high_bit);
	ans.emplace_back(2, x, y);
	y ^= x;

	auto[g, a, b] = extEuclid(x, y);

	//xa + yb = 1

	if (a < 0 and ((-a) & 1)) {
		a -= y;
		b += x;
	} else if ((-b) & 1) {
		a += y;
		b -= x;
	}

	ll num1 = multiple(x, abs(a));
	ll num2 = multiple(y, abs(b));
	ans.emplace_back(2, num2, num1);

	cout << ans.size() << '\n';
	for (auto& [t, x, y] : ans) {
		if (t == 1) {
			cout << x << " + " << y << '\n';
		} else {
			cout << x << " ^ " << y << '\n';
		}
	}
	return 0;
}