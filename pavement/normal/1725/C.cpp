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

const int MOD = 998244353;
int N, M, cnt, sum_D, res, D[300005], has[300005], fac[300005], inv_fac[300005];

int dist(int x, int y) {
	return D[y - 1] - D[x - 1];
}

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

int nck(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	fac[0] = inv_fac[0] = 1;
	for (int i = 1; i <= max(N, M); i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv_fac[i] = exp_mod(fac[i], MOD - 2);
	}
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		sum_D += D[i];
		D[i] += D[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		int lo = 1, hi = i - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (dist(mid, i) * 2 == sum_D) {
				has[mid] = 1;
				has[i] = 2;
				break;
			} else if (dist(mid, i) * 2 < sum_D) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (has[i] == 1) cnt++;
	for (int j = 0; j <= cnt; j++) {
		int curr = nck(cnt, j) * nck(M, j) % MOD * fac[j] % MOD * exp_mod((M - j) * (M - j - 1) % MOD, cnt - j) % MOD * exp_mod(M - j, N - 2 * cnt) % MOD;
		//~ cout << curr << ' ' << nck(cnt, j) << ' ' << nck(M, j) << ' ' << exp_mod((M - j) * (M - j - 1) % MOD, cnt - j) << '\n';;
		res = (res + curr) % MOD;
	}
	cout << res << '\n';
}