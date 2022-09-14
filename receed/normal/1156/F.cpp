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

const int N = 5002, MOD = 998244353;
ll dp[N][N], a[N], c[N], f[N], rf[N];

ll pw(ll x, ll k) {
	ll ans = 1;
	for (int i = 30; i >= 0; i--) {
		ans = ans * ans % MOD;
		if (k & (1 << i))
			ans = ans * x % MOD;
	}
	return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		cin >> a[i];	
		c[a[i]]++;
	}
	dp[0][0] = 1;
	f[0] = rf[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % MOD;
		rf[i] = rf[i - 1] * pw(i, MOD - 2) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		rep(j, n + 1)
			dp[i][j] = dp[i - 1][j];
		rep(j, n)
			dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j] * c[i]) % MOD;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] < 2)
			continue;
		rep(j, n - 1)
			ans = (ans + dp[i - 1][j] * f[n - 2 - j] % MOD * c[i] % MOD * (c[i] - 1) % MOD) % MOD;
	}
	ans = ans * rf[n] % MOD;
	cout << ans;
}