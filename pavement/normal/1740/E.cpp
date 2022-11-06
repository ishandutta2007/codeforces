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

int N, P[100005], mem[100005][2];
vector<int> adj[100005];

int dp(int n, bool b) {
	if (mem[n][b] != -1) return mem[n][b];
	if (b == 0) {
		int s = 0;
		for (auto u : adj[n]) {
			s += max(dp(u, 0), dp(u, 1));
		}
		mem[n][b] = s;
	} else {
		int s = 0;
		for (auto u : adj[n]) {
			s = max(s, dp(u, 1));
		}
		s++;
		mem[n][b] = s;
	}
	//~ cout << "DP " << n << ' ' << b << ' ' << mem[n][b] << '\n';
	return mem[n][b];
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> P[i];
		adj[P[i]].pb(i);
	}
	cout << max(dp(1, 0), dp(1, 1)) << '\n';
}