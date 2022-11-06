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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;
int ans, ans2 = 1, cnt, N, K, H[200005], fac[200005], inv[200005];

int exp_mod(int a, int b) {
	int r = 1ll;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

int nck(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = exp_mod(fac[i], MOD - 2);
	}
	for (int i = 1; i <= N; i++) {
		if (H[i] == H[i % N + 1]) ans2 = (ans2 * K) % MOD;
		else cnt++;
	}
	for (int s = 0; s <= cnt; s++) {
		if (s & 1) ans = (ans + nck(cnt, s) * exp_mod(K - 2, cnt - s) % MOD * exp_mod(2, s - 1) % MOD) % MOD;
		else ans = (ans + nck(cnt, s) * exp_mod(K - 2, cnt - s) % MOD * (exp_mod(2, s) - nck(s, s / 2)) % MOD * exp_mod(2, MOD - 2) % MOD) % MOD;
	}
	cout << (ans * ans2 % MOD + MOD) % MOD << '\n';
}