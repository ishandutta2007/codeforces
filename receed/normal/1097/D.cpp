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
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 52, K = 10001, MOD = 1000000007;
ll dp[N][N], ps[N + 1], rr[N];
vector<pair<ll, ll>> a;
ll n, k;
ll ans;

ll pw(ll x, ll p) {
	if (p == 0)
		return 1;
	if (p % 2)
		return pw(x, p - 1) * x % MOD;
	return pw(x * x % MOD, p / 2);
}
ll rev(ll x) {
	return pw(x, MOD - 2);
}

void go(int p, ll pr) {
	if (p == a.size()) {
		ans = (ans + pr) % MOD;
		return;
	}
	for (int i = 0; i <= a[p].second; i++) {
		go(p + 1, pr * dp[a[p].second][i] % MOD);
		pr = pr * a[p].first % MOD;
	}
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < N; i++)
		rr[i] = rev(i + 1);
	rep(i, N)
		dp[i][i] = 1;
	rep(i, k) {
		rep(i, N) {
			ll cs = 0;
			for (int j = i; j < N; j++) {
				cs = (cs + dp[j][i]) % MOD;
				dp[j][i] = cs * rr[j] % MOD;
			}
		}
	}
	for (ll i = 2; i * i <= n; i++) {
		if (n % i)
			continue;
		int t = 0;
		while (n % i == 0) {
			n /= i;
			t++;
		}
		a.push_back({i % MOD, t});
	}
	if (n > 1)
		a.push_back({n % MOD, 1});
	go(0, 1);
	cout << ans;
}