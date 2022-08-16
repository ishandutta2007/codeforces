#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n;
ll a[N];

ll check(ll x) {
	vector<ll> fact;
	for (int i = 2; (ll)i * i <= x; i++) {
		if (x % i == 0) {
			fact.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}

	if (x > 1) {
		fact.push_back(x);
	}

	ll ans = LLONG_MAX;
	for (ll p : fact) {
		ll temp = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < p) {
				temp += p - a[i];
			} else {
				temp += min(p - a[i] % p, a[i] % p);
			}
		}
		ans = min(ans, temp);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	mt19937_64 rng((int)a);
	uniform_int_distribution<int> uid(0, n - 1);

	ll ans = n;
	for (int i = 0; i < 20; i++) {
		ll x = a[uid(rng)];
		for (ll j = x - 1; j <= x + 1; j++) {
			if (j > 1) {
				ans = min(ans, check(j));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}