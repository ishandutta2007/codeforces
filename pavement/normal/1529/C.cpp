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

int T, N, L[100005], R[100005], mem[100005][3];
vector<int> adj[100005];

int dp(int n, int k, int e = -1) {
	if (mem[n][k] != -1) return mem[n][k];
	// try A[n] = L[n]
	int ret1;
	if (k == 0) ret1 = llabs(L[n] - L[e]);
	else if (k == 1) ret1 = llabs(L[n] - R[e]);
	else ret1 = 0;
	for (auto u : adj[n]) if (u != e)
		ret1 += dp(u, 0, n);
	int ret2;
	if (k == 0) ret2 = llabs(R[n] - L[e]);
	else if (k == 1) ret2 = llabs(R[n] - R[e]);
	else ret2 = 0;
	for (auto u : adj[n]) if (u != e)
		ret2 += dp(u, 1, n);
	return mem[n][k] = max(ret1, ret2);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) adj[i].clear();
		for (int i = 1; i <= N; i++)
			for (int j = 0; j <= 2; j++) mem[i][j] = -1;
		for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		cout << dp(1, 2) << '\n';
	}
}