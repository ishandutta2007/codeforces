#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

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

ll fact[N], inv[N];
ll choose(int n, int k) {
    return fact[n] * inv[n - k] % mod * inv[k] % mod;
}

int n, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = i * fact[i - 1] % mod;
		inv[i] = modinv(fact[i]);
	}

	cin >> n;
	for (int i = 0; i < 2 * n; i++) cin >> a[i];

	sort(a, a + 2 * n);

	ll diff = (accumulate(a + n, a + 2 * n, 0ll) - accumulate(a, a + n, 0ll)) % mod;
	cout << choose(2 * n, n) * diff % mod << '\n';
	return 0;
}