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
typedef tree<iii, null_type, greater<iii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, K, ans, fac[100005], invfac[100005];
const int MOD = 1e9 + 7;

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return r;
}

int choose(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fac[0] = 1;
	invfac[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		fac[i] = i * fac[i - 1] % MOD;
		invfac[i] = exp_mod(fac[i], MOD - 2);
	}
	cin >> T;
	while (T--) {
		cin >> N >> K;
		int ans = 1;
		for (int i = 1; i < N; i++) {
			// calculate the probability of >= i - 1 turns = probability that you reach a valid state in i turns
			ans = (ans + choose(N - (K - 1) * (i - 1), i) * fac[i] % MOD * exp_mod(fac[N] * invfac[N - i] % MOD, MOD - 2) % MOD) % MOD;
		}
		cout << ans << '\n';
	}
}