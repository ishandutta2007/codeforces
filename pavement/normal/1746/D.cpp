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

int T, N, K, S[200005];
vector<int> adj[200005];
map<int, int> mem[200005];

int dp(int n, int k) {
	if (mem[n].find(k) != mem[n].end()) return mem[n][k];
	//~ cout << "@ " << n << ' ' << k << '\n';
	int ret = S[n] * k;
	
	if (adj[n].size() == 0) return mem[n][k] = ret;
	
	int lo = k / adj[n].size(), hi = (k + adj[n].size() - 1) / adj[n].size();
	
	if (lo == hi) {
		for (auto u : adj[n]) {
			ret += dp(u, lo);
		}
	} else {
		int rem = k % adj[n].size();
		vector<int> vec;
		for (auto u : adj[n]) {
			int tmp = dp(u, lo);
			ret += tmp;
			vec.pb(dp(u, hi) - tmp);
		}
		sort(vec.begin(), vec.end(), greater<int>());
		for (int i = 0; i < rem; i++)
			ret += vec[i];
	}
	return mem[n][k] = ret;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 2, p; i <= N; i++) {
			cin >> p;
			adj[p].pb(i);
		}
		for (int i = 1; i <= N; i++) {
			cin >> S[i];
		}
		cout << dp(1, K) << '\n';
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			mem[i].clear();
		}
	}
}