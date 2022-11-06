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

const int MOD = 1e9 + 7;
int N, K, ans, sz[200005], fac[200005], inv[200005], par[200005];
vector<int> adj[200005];

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
	return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int dfs(int n, int e = -1) {
	par[n] = e;
	sz[n] = 1;
	for (auto u : adj[n]) if (u != e)
		sz[n] += dfs(u, n);
	return sz[n];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = exp_mod(fac[i], MOD - 2);
	}
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		vector<int> sizes;
		for (int j : adj[i])
			if (j == par[i]) sizes.pb(N - sz[i]);
			else sizes.pb(sz[j]);
		// case r = i
		int tmp = 0;
		for (int j : sizes) {
			tmp += nck(j, K);
			tmp %= MOD;
		}
		ans += N * (nck(N - 1, K) - tmp + nck(N - 1, K - 1)) % MOD;
		ans %= MOD;
		// case r != i
		for (int j : sizes) {
			tmp -= nck(j, K);
			tmp %= MOD;
			ans += (N - j) * j % MOD * (nck(N - 1 - j, K) - tmp + nck(N - 1 - j, K - 1));
			ans %= MOD;
			tmp += nck(j, K);
			tmp %= MOD;
		}
	}
	cout << (ans % MOD + MOD) % MOD << '\n';
}