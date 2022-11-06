#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, X, dep[1005], cnt[1005];
vector<int> adj[1005];

void dfs(int n, int e = -1) {
	cnt[dep[n]]++;
	for (auto u : adj[n])
		if (u != e) {
			dep[u] = dep[n] + 1;
			dfs(u, n);
		}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(dep, 0, sizeof dep);
		memset(cnt, 0, sizeof cnt);
		cin >> N >> X;
		for (int i = 1; i <= N; i++)
			adj[i].clear();
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		if (adj[X].size() <= 1) {
			cout << "Ayush\n";
			continue;
		}
		dfs(X);
		bool curr = 0;
		for (int i = N; i >= 0; i--)
			curr ^= (cnt[i] & 1);
		cout << (curr ? "Ashish" : "Ayush") << '\n';
	}
}