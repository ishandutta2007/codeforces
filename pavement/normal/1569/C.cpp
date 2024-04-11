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

const int MOD = 998244353;
int T, N, A[200005], fac[200005], invfac[200005];

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return r;
}

int npk(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] % MOD * invfac[n - k] % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = exp_mod(fac[i], MOD - 2);
	}
	while (T--) {
		int mx = 0, cntm = 0, cnta = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (A[i] > mx) {
				mx = A[i];
				cntm = 1;
			} else if (A[i] == mx) cntm++;
		}
		if (cntm > 1) cout << fac[N] << '\n';
		else {
			for (int i = 1; i <= N; i++)
				if (A[i] == mx - 1) cnta++;
			if (cnta == 0) cout << "0\n";
			else {
				int ans = 0;
				for (int i = 1; i <= N; i++)
					ans += npk(i - 1, cnta) * npk(N - cnta - 1, i - 1 - cnta) % MOD * fac[N - i] % MOD, ans %= MOD;
				cout << ((fac[N] - ans) % MOD + MOD) % MOD << '\n';
			}
		}
	}
}