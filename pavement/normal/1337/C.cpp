#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
typedef long double ld;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, K, T, sz[200005], dist[200005], V[200005];
bool C[200005];
vector<int> adj[200005];

int dfs(int n, int e, int d) {
	dist[n] = d;
	sz[n] = 1;
	for (auto u : adj[n])
		if (u != e) sz[n] += dfs(u, n, d + 1);
	return sz[n];
}

void dfs2(int n, int e, int acc) {
	if (C[n]) T += acc;
	else acc++;
	for (auto u : adj[n])
		if (u != e) dfs2(u, n, acc);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1, 0);
	for (int i = 1; i <= N; i++) V[i] = i;
	sort(V + 1, V + 1 + N, [](const auto &lhs, const auto &rhs) {
		return dist[lhs] - sz[lhs] > dist[rhs] - sz[rhs];
	});
	for (int i = 1; i <= K; i++) C[V[i]] = 1;
	dfs2(1, -1, 0);
	cout << T << '\n';
}