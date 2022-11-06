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

int N, ans, lw, lq, rb, rq, qq, fac[100005], invfac[100005];
string S[100005];
bool ok, c1, c2;
const int MOD = 998244353;

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
	return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	fac[0] = 1;
	invfac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = exp_mod(fac[i], MOD - 2);
	}
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		if (S[i] == "WW" || S[i] == "BB") ok = 1;
		if (S[i][0] == 'W') lw++;
		else if (S[i][0] == '?') lq++;
		if (S[i][1] == 'B') rb++;
		else if (S[i][1] == '?') rq++;
	}
	for (int k = lw; k <= lw + lq; k++) {
		ans += nck(lq, k - lw) * nck(rq, k - rb);
		ans %= MOD;
	}
	if (!ok) {
		c1 = c2 = 1;
		for (int i = 1; i <= N; i++) {
			if (S[i] == "??") qq++;
			if (S[i][0] == 'B' || S[i][1] == 'W') c1 = 0;
			if (S[i][0] == 'W' || S[i][1] == 'B') c2 = 0;
		}
		ans -= exp_mod(2, qq);
		ans %= MOD;
		if (qq == N) ans += 2;
		else ans += c1 + c2;
	}
	cout << (ans % MOD + MOD) % MOD << '\n';
}