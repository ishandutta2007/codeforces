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

int N, M, K, ansl, ansr, ansl2, ansr2, dep[100005], cursz[100005];
bool vis[100005];
vector<int> path, tadj[100005];
vector<ii> adj[100005];
set<ii> pq;

void dfs(int n) {
	//cout << "DFS " << n << '\n';
	for (auto u : adj[n])
		if (!vis[u.second]) {
			if (dep[u.first] == -1) {
				tadj[n].pb(u.first);
				tadj[u.first].pb(n);
				//cout << "TEDGE " << n << ' ' << u.first << '\n';
				vis[u.second] = 1;
				dep[u.first] = dep[n] + 1;
				dfs(u.first);
			} else if (dep[u.first] > dep[n]) {
				vis[u.second] = 1;
				if (dep[u.first] - dep[n] < K) {
					ansl = u.first;
					ansr = n;
				} else {
					ansl2 = u.first;
					ansr2 = n;
				}
				//cout << "BEDGE " << n << ' ' << u.first << '\n';
			}
		}
}

bool getPath(int n, int x, int e = -1) {
	if (n == x) {
		path.pb(n);
		return 1;
	}
	for (auto u : tadj[n])
		if (u != e && getPath(u, x, n)) {
			path.pb(n);
			return 1;
		}
	return 0;
}

bool curset = 0;
vector<int> sets[2];

void dfs2(int n, int e = -1) {
	bool nowset = curset;
	for (auto u : tadj[n])
		if (u != e) {
			if (curset == nowset) curset ^= 1;
			sets[curset].pb(u);
			dfs2(u, n);
		}
}

main() {
	memset(dep, -1, sizeof dep);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1, u, v; i <= M; i++) {
		cin >> u >> v;
		adj[u].eb(v, i);
		adj[v].eb(u, i);
	}
	dep[1] = 0;
	dfs(1);
	if (ansl) {
		getPath(ansl, ansr);
		cout << "2\n" << path.size() << '\n';
		for (int i : path) cout << i << ' ';
		cout << '\n';
		return 0;
	} else if (ansl2) {
		getPath(ansl2, ansr2);
		cout << "1\n";
		for (int i = 0, total = 0; total < (K + 1) / 2; total++, i += 2) cout << path[i] << ' ';
		cout << '\n';
	} else {
		vector<int> is;
		assert(M == N - 1);
		sets[0].pb(1);
		dfs2(1);
		if (sets[0].size() < sets[1].size()) swap(sets[0], sets[1]);
		assert(sets[0].size() >= (K + 1) / 2);
		cout << "1\n";
		for (int i = 0; i < (K + 1) / 2; i++) cout << sets[0][i] << ' ';
		cout << '\n';
	}
}