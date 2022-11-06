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

int T, N, ans, idx, pre[300005], sz[300005];
vector<int> adj[300005], adj2[300005];
set<ii> S;

int dfs2(int n) {
	pre[n] = ++idx;
	sz[n] = 1;
	for (auto u : adj2[n])
		sz[n] += dfs2(u);
	return sz[n];
}

void dfs(int n) {
	ii tmp = mp(-1, -1);
	auto it = S.upper_bound(make_pair(pre[n], pre[n] + sz[n] - 1));
	bool cov = 0;
	if (it != S.end() && it->second <= pre[n] + sz[n] - 1) cov = 1;
	if (!cov) {
		if (it != S.begin()) {
			--it;
			if (it->second >= pre[n] + sz[n] - 1) tmp = *it, S.erase(it);
		}
		S.emplace(pre[n], pre[n] + sz[n] - 1);
	}
	ans = max(ans, (int)S.size());
	for (auto u : adj[n]) dfs(u);
	if (tmp.first != -1) S.insert(tmp);
	S.erase(S.find(mp(pre[n], pre[n] + sz[n] - 1)));
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			sz[i] = pre[i] = 0, adj[i].clear(), adj2[i].clear();
		idx = ans = 0;
		S.clear();
		for (int i = 2, p; i <= N; i++) {
			cin >> p;
			adj[p].pb(i);
		}
		for (int i = 2, p; i <= N; i++) {
			cin >> p;
			adj2[p].pb(i);
		}
		dfs2(1);
		dfs(1);
		cout << ans << '\n';
	}
}