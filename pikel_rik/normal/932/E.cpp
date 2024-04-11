#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

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

const int K = 5000;

int n, k, dp[K + 1][K + 1];

int recurse(int kk, int nn) {
	if (dp[kk][n - nn] != -1) {
		return dp[kk][n - nn];
	}
	if (kk == 0) {
		return dp[kk][n - nn] = modexp(2, nn);
	}
	dp[kk][n - nn] = (ll)(n - nn) * recurse(kk - 1, nn) % mod;
	dp[kk][n - nn] = (dp[kk][n - nn] + (ll)nn * recurse(kk - 1, nn - 1)) % mod;
	return dp[kk][n - nn];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << recurse(k, n) << '\n';
	return 0;
}