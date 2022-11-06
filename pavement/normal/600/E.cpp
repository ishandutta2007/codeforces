#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, C[100005], cmax[100005], smax[100005], ans[100005];
map<int, int> M[100005];
vector<int> adj[100005];

void dfs(int n, int e = -1) {
	M[n][C[n]]++;
	cmax[n] = 1;
	smax[n] = C[n];
	for (auto u : adj[n]) {
		if (u == e) continue;
		dfs(u, n);
		if (M[u].size() > M[n].size()) {
			swap(M[n], M[u]);
			swap(cmax[n], cmax[u]);
			swap(smax[n], smax[u]);
		}
		for (auto i : M[u]) {
			M[n][i.first] += i.second;
			if (M[n][i.first] > cmax[n]) {
				cmax[n] = M[n][i.first];
				smax[n] = i.first;
			} else if (M[n][i.first] == cmax[n]) {
				smax[n] += i.first;
			}
		}
	}
	ans[n] = smax[n];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int u, v, i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
	cout << '\n';
}