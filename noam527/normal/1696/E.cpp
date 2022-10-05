#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int N = 500005;

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

ll fac[N], ifac[N];

void prep() {
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = i * fac[i - 1] % md;
		ifac[i] = inv(i) * ifac[i - 1] % md;
	}
}

ll choose(ll n, ll k) {
	return fac[n] * ifac[k] % md * ifac[n - k] % md;
}

int n;
vector<int> a;

void solve() {
	prep();
	cin >> n;
	a.resize(n + 1);
	for (auto &i : a) cin >> i;
	ll ans = 0;
	for (int y = 0; y < n + 1; y++) {
		if (a[y] == 0) break;
		ans += choose(a[y] + y, y + 1);
	}
	cout << ans % md << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}