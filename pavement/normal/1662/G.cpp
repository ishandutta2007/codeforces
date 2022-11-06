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

bitset<1000005> bs;
int N, ans, ans2, cent, cnt[1000005], sz[1000005];
vector<int> vec, adj[1000005];

int dfs(int n, int e = -1) {
	sz[n] = 1;
	int m = 0;
	for (auto u : adj[n]) if (u != e) {
		sz[n] += dfs(u, n);
		m = max(m, sz[u]);
	}
	m = max(m, N - sz[n]);
	if (m <= N / 2) cent = n;
	return sz[n];
}

void get_dist(int n, int e = -1, int d = 0) {
	ans += d;
	for (auto u : adj[n]) if (u != e) get_dist(u, n, d + 1);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 2, P; i <= N; i++) {
		cin >> P;
		adj[P].pb(i);
		adj[i].pb(P);
	}
	dfs(1);
	ans = N;
	get_dist(cent);
	for (auto i : adj[cent])
		if (sz[i] > sz[cent]) cnt[N - sz[cent]]++;
		else cnt[sz[i]]++;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 30; j++)
			if (cnt[i] >= (1 << j)) {
				cnt[i] -= (1 << j);
				vec.eb(i * (1 << j));
			}
		if (cnt[i]) vec.eb(i * cnt[i]);
	}
	bs.reset();
	bs[0] = 1;
	for (auto i : vec) bs = bs | (bs << i);
	for (int i = 0; i <= N; i++)
		if (bs[i]) ans2 = max(ans2, i * (N - 1 - i));
	cout << ans + ans2 << '\n';
}