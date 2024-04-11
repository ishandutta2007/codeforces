
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7, sz = 2e5 + 5;
int n, m, g;
ll f[sz], finv[sz];

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
	const int mx = 200000;
	f[0] = 1;
	foru(i, 1, mx + 1)f[i] = (f[i - 1] * i) % mod;
	finv[mx] = modpow(f[mx], mod - 2);
	ford(i, mx - 1, 0)finv[i] = (finv[i + 1] * (i + 1)) % mod;
}

ll choose(int n, int k) {
	if (k > n)return 0;
	ll mul = (f[n] * finv[k]) % mod;
	return (mul * finv[n - k]) % mod;
}

ll foo(int z, int o) {
	if (!z) return (o > 1);
	ll tot = 0;
	if (o)tot += choose(z + o - 1, o - 1);
	if (z)tot += choose(z + o - 1, z - 1) - foo(z - 1, o);
	return (tot + mod) % mod;
}

int main() {
	fast;
	prec();
	cin >> n >> m >> g;
	if (g)cout << (choose(n + m, n) -foo(n, m) + mod) % mod;
	else cout << foo(n, m);
	return 0;
}