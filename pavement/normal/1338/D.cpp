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

int N, ans, par[100005], mem[100005][2];
vector<int> adj[100005];

void init(int n, int e = -1) {
	par[n] = e;
	for (auto u : adj[n]) if (u != e) init(u, n);
}

int dp(int n, bool b) {
	if (mem[n][b] != -1) return mem[n][b];
	if (b) {
		int ret = 1;
		for (auto u : adj[n]) if (u != par[n])
			ret = max(ret, 1 + dp(u, 0));
		//~ cout << "DP " << n << ' ' << b << ' ' << ret << '\n';
		return mem[n][b] = ret;
	} else {
		int ret = 0;
		for (auto u : adj[n]) if (u != par[n])
			ret = max(ret, (int)adj[n].size() - (n != 1) - 1 + max(dp(u, 0), dp(u, 1)));
		//~ cout << "DP " << n << ' ' << b << ' ' << ret << ' ' << (int)adj[n].size() - (n != 1) << '\n';
		return mem[n][b] = ret;
	}
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	init(1);
	for (int i = 1; i <= N; i++) {
		// if chosen
		vector<int> tmp;
		for (auto u : adj[i]) if (u != par[i])
			tmp.pb(dp(u, 0));
		sort(tmp.begin(), tmp.end(), greater<int>());
		int curr = 1;
		for (int i = 0; i < min((int)tmp.size(), 2ll); i++) curr += tmp[i];
		//~ cout << i << " chosen " << curr << '\n';
		ans = max(ans, curr);
		// if not chosen
		tmp.clear();
		for (auto u : adj[i]) if (u != par[i])
			tmp.pb(max(dp(u, 1), dp(u, 0)));
		sort(tmp.begin(), tmp.end(), greater<int>());
		curr = max(0ll, (int)tmp.size() - 2 + (i != 1));
		for (int i = 0; i < min((int)tmp.size(), 2ll); i++) curr += tmp[i];
		//~ cout << i << " not chosen " << curr << '\n';
		ans = max(ans, curr);
	}
	cout << ans << '\n';
}