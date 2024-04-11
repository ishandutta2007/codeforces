#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <typename T>
vector<pair<T, int>> primeFactors(T n) {
    vector<pair<T, int>> factors;
    for (int i = 2; (T)i * i <= n; i++) {
        if (n % i == 0) {
            factors.emplace_back(i, 0);
            while (n % i == 0) {
                n /= i;
                factors.back().second++;
            }
        }
    }
    if (n > 1) {
        factors.emplace_back(n, 1);
    }
    return factors;
}

ll pow(ll p, ll n) {
	ll ans = 1;
	while (n--) {
		ans *= p;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		ll p, q;
		cin >> p >> q;

		if (p % q != 0) {
			cout << p << '\n';
		} else {
			auto fact = primeFactors(q);
			ll ans = 1;

			for (auto &[pp, c] : fact) {
				ll pw = pow(pp, c), val = p;
				while (val % pw == 0) {
					val /= pp;
				}
				ans = max(ans, val);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}