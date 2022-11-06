#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, K, fac[2005];
const int MOD = 998244353;

int exp_mod(int a, int b) {
	a %= MOD;
	b %= (MOD - 1);
	int r = 1ll;
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
	cin >> N >> M >> K;
	fac[0] = 1;
	for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % MOD;
	int T = fac[N - 1] * exp_mod(fac[K] * fac[N - K - 1] % MOD, MOD - 2) % MOD;
	cout << T * M % MOD * exp_mod(M - 1, K) % MOD << '\n';
}