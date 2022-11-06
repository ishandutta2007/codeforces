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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, link[200005], sz[200005];
vector<int> vec, adj[200005];
set<int> vis;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

void dfs(int x) {
	vis.erase(x);
	int prv = 0;
	while (vis.upper_bound(prv) != vis.end()) {
		auto it = vis.upper_bound(prv);
		prv = *it;
		if (!binary_search(adj[x].begin(), adj[x].end(), prv)) {
			unite(x, prv);
			dfs(prv);
		}
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		link[i] = i;
		sz[i] = 1;
		vis.insert(i);
	}
	for (int u, v; M--; ) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	for (int i = 1; i <= N; i++)
		if (vis.find(i) != vis.end()) dfs(i);
	for (int i = 1; i <= N; i++)
		if (i == find(i)) vec.pb(sz[i]);
	sort(vec.begin(), vec.end());
	cout << vec.size() << '\n';
	for (int i : vec) cout << i << ' ';
	cout << '\n';
}