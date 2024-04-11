#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int N = 300005;

ll f[N];
ll fac[N], ifac[N];

ll pw(ll b, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}
ll inv(ll x) {
	return pw(x, md - 2);
}

void prep() {
	f[0] = f[1] = 1;
	f[2] = 2;
	for (int n = 3; n < N; n++) {
		f[n] = (f[n - 1] + (ll)(n - 1) * f[n - 2]) % md;
	}
	fac[0] = ifac[0] = 1;
	for (int n = 1; n < N; n++) {
		fac[n] = fac[n - 1] * n % md;
		ifac[n] = ifac[n - 1] * inv(n) % md;
	}
}

int n;

void solve() {
	cin >> n;
	ll ans = 0;
	for (int k = 0; 4 * k <= n; k++) {
		ll cur = fac[n - 2 * k];
		cur = cur * ifac[n - 4 * k] % md;
		//cur = cur * pw(2, k) % md;
		cur = cur * ifac[k] % md;
		cur = cur * f[n - 4 * k];
		//cur = cur * ifac[2] % md;
		ans = (ans + cur) % md;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	prep();
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}