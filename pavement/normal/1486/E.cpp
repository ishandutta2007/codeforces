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

int N, M, dist[100005][55][2];
vector<ii> adj[100005];
priority_queue<iiii, vector<iiii>, greater<iiii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 55; j++)
			for (int k = 0; k < 2; k++)
				dist[i][j][k] = (int)1e17;
	dist[1][0][0] = 0;
	pq.emplace(0, 1, 0, 0);
	while (!pq.empty()) {
		auto [d, v, x, b] = pq.top();
		pq.pop();
		if (d != dist[v][x][b]) continue;
		for (auto [u, w] : adj[v])
			if ((!b ? w * w : w * (w + 2 * x)) + d < dist[u][w][!b]) {
				dist[u][w][!b] = (!b ? w * w : w * (w + 2 * x)) + d;
				pq.emplace(dist[u][w][!b], u, w, !b);
			}
	}
	for (int i = 1; i <= N; i++) {
		int curr = (int)1e17;
		for (int j = 0; j < 55; j++)
			curr = min(curr, dist[i][j][0]);
		if (curr >= (int)1e17) cout << "-1 ";
		else cout << curr << ' ';
	}
}