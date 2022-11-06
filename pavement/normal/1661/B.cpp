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


const int MOD = 32768;
int N, A[40005], dist[40005];
vector<int> adj[40005];
queue<ii> Q;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < MOD; i++) {
		adj[(i + 1) % MOD].pb(i);
		adj[(2 * i) % MOD].pb(i);
		dist[i] = 1e9;
	}
	dist[0] = 0;
	Q.emplace(0, 0);
	while (!Q.empty()) {
		auto [d, v] = Q.front();
		Q.pop();
		if (d != dist[v]) continue;
		for (auto u : adj[v])
			if (d + 1 < dist[u]) {
				dist[u] = d + 1;
				Q.emplace(dist[u], u);
			}
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		cout << dist[A[i]] << ' ';
	}
	cout << '\n';
}