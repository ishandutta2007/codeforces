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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
int N, K, ans, fac[1000005], inv_fac[1000005];

int nck(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

int exp_mod(int a, int b) {
	if (a < 0 || b < 0) return 0;
	a %= MOD;
	b %= (MOD - 1);
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fac[0] = inv_fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv_fac[i] = exp_mod(fac[i], MOD - 2);
	}
	if (K == 0) return cout << exp_mod(3, N) << '\n', 0;
	for (int seg = 1; seg <= N; seg++) {
		// seg number of 1-1
		// seg - 1 number of 0-0
		ans += nck(K - 1, seg - 1) * exp_mod(3, K - seg) % MOD * nck(seg - 1 + N - K - (seg - 1), seg - 1) % MOD * exp_mod(3, N - K - (seg - 1)) % MOD;
		ans %= MOD;
		// seg number of 1-1
		// seg number of 0-0
		ans += nck(K - 1, seg - 1) * exp_mod(3, K - seg) % MOD * nck(seg + N - K - (seg), seg) % MOD * exp_mod(3, N - K - seg) % MOD;
		ans %= MOD;
		//~ cout << nck(K - 1, seg - 1) * exp_mod(3, K - seg) % MOD * nck(seg - 1 + N - K - (seg - 1), seg - 1) % MOD * exp_mod(3, N - K - (seg - 1)) % MOD << ' ' << nck(K - 1, seg - 1) * exp_mod(3, K - seg) % MOD * nck(seg + N - K - (seg - 1), seg) % MOD * exp_mod(3, N - K - seg) % MOD << '\n';
	}
	cout << ans << '\n';
}