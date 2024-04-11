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

int T, N, K, idx, l[200005], r[200005], tmp[200005], X[200005], dep[200005];
vector<int> vec, adj[200005];

void dfs(int n, int e = -1) {
	vec.pb(n);
	int lo = 0, hi = (int)vec.size() - 1, ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (dep[n] - dep[vec[mid]] <= dep[vec[mid]]) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	assert(ans != -1);
	tmp[n] = vec[ans];
	l[n] = 1e9;
	r[n] = -1e9;
	for (auto u : adj[n])
		if (u != e) {
			dep[u] = dep[n] + 1;
			dfs(u, n);
			l[n] = min(l[n], l[u]);
			r[n] = max(r[n], r[u]);
		}
	if (adj[n].size() == 1 && n != 1) {
		l[n] = r[n] = ++idx;
	}
	vec.ppb();
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= K; i++) cin >> X[i];
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		map<int, int> mm;
		for (int i = 1; i <= K; i++) {
			assert(tmp[X[i]] != -1);
			mm[l[tmp[X[i]]]] = max(mm[l[tmp[X[i]]]], r[tmp[X[i]]]);
			//cout << "!: " << l[tmp[X[i]]] << ' ' << r[tmp[X[i]]] << '\n';
		}
		int lim = 0, currf = 0, used = 0;
		bool cannot = 0;
		assert(idx >= 0);
		for (int i = 1; i <= idx; i++) {
			currf = max(currf, mm[i]);
			if (i > lim) {
				if (currf <= lim) cannot = 1;
				lim = currf;
				currf = 0;
				used++;
			}
		}
		if (cannot) cout << "YES\n";
		else cout << "NO\n";
		vec.clear();
		idx = 0;
		for (int i = 1; i <= N; i++) {
			tmp[i] = -1;
			dep[i] = 0;
			X[i] = 0;
			adj[i].clear();
		}
	}
}