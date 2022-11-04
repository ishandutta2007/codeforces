#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const ll MOD = 1e9 + 7;
ll mod(ll x) {
	ll res = x % MOD;
	if (res < 0) {
		return res + MOD;
	}
	return res;
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	ll k = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int p = 1; p <= 3; p++) {
				if (i + j + p == 6) {
					k++;
				}
			}
		}
	}

	ll ans = 1;
	for (int i = 0; i < 3 * n; i++) {
		ans *= 3;
		ans = mod(ans);
	}

	ll m = 1;
	for (int i = 0; i < n; i++) {
		m *= k;
		m = mod(m);
	}

	cout << mod(ans - m) << endl;

	return 0;
}