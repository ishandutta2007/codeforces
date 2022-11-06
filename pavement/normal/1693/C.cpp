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

int N, M, cnt[200005], ans[200005], out[200005];
vector<int> adj[200005];
priority_queue<ii, vector<ii>, greater<ii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int u, v; M--; ) {
		cin >> u >> v;
		adj[v].pb(u);
		out[u]++;
	}
	for (int i = 1; i < N; i++) ans[i] = 1e16;
	ans[N] = 0;
	pq.emplace(0, N);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d != ans[u]) continue;
		for (auto v : adj[u]) {
			if (ans[v] > d + out[v] - cnt[v]) {		
				ans[v] = d + out[v] - cnt[v];
				pq.emplace(ans[v], v);
			}
			cnt[v]++;
		}
	}
	cout << ans[1] << '\n';
}