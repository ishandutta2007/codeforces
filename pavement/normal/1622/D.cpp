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
int N, K, cnt, ans, fac[5005], invfac[5005];
char S[5005];

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
	return fac[n] * invfac[n - k] % MOD * invfac[k] % MOD;
}

int aux(int l, int r) {
	int cum = 0;
	for (int i = l; i <= r; i++)
		if (S[i] == '1') cum++;
	if (S[l] == '1') return cum;
	else return cum - 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fac[0] = 1;
	invfac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = exp_mod(fac[i], MOD - 2);
	}
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		if (S[i] == '1') cnt++;
	}
	if (cnt < K) return cout << "1\n", 0;
	for (int i = 1; i <= N; i++) {
		int j, tmp = 0;
		for (j = i; j <= N; j++) {
			if (S[j] == '1') tmp++;
			if (tmp > K) break;
		}
		ans = (ans + nck(j - i - 1, aux(i, j - 1))) % MOD;
	}
	cout << (ans + 1) % MOD << '\n';
}