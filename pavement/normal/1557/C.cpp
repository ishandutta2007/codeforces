#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1e9 + 7;
int T, N, K, fac[200005], invfac[200005];

int exp_mod(int a, int b) {
	int r = 1ll;
	while (b) {
		if (b & 1) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

int nck(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fac[0] = 1;
	invfac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = exp_mod(fac[i], MOD - 2);
	}
	cin >> T;
	while (T--) {
		cin >> N >> K;
		int tmp = 0, ans = 0, cnt = 1;
		for (int i = 0; i < N; i += 2) tmp += nck(N, i), tmp %= MOD;
		for (int i = K - 1; i >= 0; i--) { // bit first differs at i
			if (N % 2 == 0) ans += (cnt * exp_mod(exp_mod(2, i), N)) % MOD;
			ans %= MOD;
			cnt *= ((N & 1 ? 1 : 0) + tmp) % MOD;
			ans %= MOD;
			cnt %= MOD;
		}
		ans += cnt;
		ans %= MOD;
		cout << ans << '\n';
	}
}