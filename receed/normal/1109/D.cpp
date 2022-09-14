#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1000005, MOD = 1000000007;
ll f[N];

ll pw(ll x, ll k) {
	if (k == 0)
		return 1;
	if (k % 2)
		return pw(x, k - 1) * x % MOD;
	return pw(x * x % MOD, k / 2);
}
ll rev(ll x) {
	return pw(x, MOD - 2);
}
ll c(ll n, ll k) {
	if (k > n)
		return 0;
	return f[n] * rev(f[k] * f[n - k] % MOD) % MOD;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = f[i - 1] * i % MOD;
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		ans = (ans + c(m - 1, i - 2) * pw(m, n - i) % MOD * pw(n, max(n - i - 1, 0ll)) % MOD * (i == n ? 1 : i) % MOD * c(n - 2, i - 2) % MOD * f[i - 2] % MOD) % MOD;
	}
	cout << ans;
}