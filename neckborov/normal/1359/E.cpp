#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;
const int N = 5e5 + 5;

ll binpow(ll a, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			(res *= a) %= mod;
		}
		p >>= 1;
		(a *= a) %= mod;
	}
	return res;
}

ll f[N], fr[N];

ll cnk(int n, int k) {
	if (k > n) return 0;
	return f[n] * fr[k] % mod * fr[n - k] % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	f[0] = fr[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] * i % mod;
		fr[i] = binpow(f[i], mod - 2);
	}
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = n / i - 1;
		(ans += cnk(cnt, k - 1)) %= mod;
	}
	cout << ans << endl;
	return 0;
}