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
int N, ans, sum, V[200005], dep[200005], run[200005][2], cnt[200005][2];
vector<int> adj[200005];

void dfs(int n, int e = -1) {
	run[n][dep[n] & 1] += V[n];
	run[n][dep[n] & 1] %= MOD;
	cnt[n][dep[n] & 1]++;
	cnt[n][dep[n] & 1] %= MOD;
	for (auto u : adj[n]) if (u != e) {
		dep[u] = dep[n] + 1;
		dfs(u, n);
		for (int k = 0; k < 2; k++) {
			int mult = ((k & 1) != (dep[n] & 1) ? 1 : -1);
			ans += mult * run[u][k] * cnt[n][k] % MOD + mult * -1 * run[n][k] * cnt[u][k] % MOD;
			ans %= MOD;
		}
		for (int k = 0; k < 2; k++) {
			run[n][k] += -run[u][k] + cnt[u][k] * V[n] % MOD;
			cnt[n][k] += cnt[u][k];
			run[n][k] %= MOD;
			cnt[n][k] %= MOD;
		}
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
		sum += V[i];
		sum %= MOD;
	}
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	cout << ((ans * 2 + sum) % MOD + MOD) % MOD << '\n';
}