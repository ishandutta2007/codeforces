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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, link[55], sz[55];
bool V[55];
vector<int> vec[55];
vector<vector<int> > ateam, team[4];

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

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		link[i] = i;
		sz[i] = 1;
	}
	for (int u, v; M--; ) {
		cin >> u >> v;
		unite(u, v);
	}
	for (int i = 1; i <= N; i++)
		vec[find(i)].pb(i);
	for (int i = 1; i <= N; i++) {
		if (V[find(i)]) continue;
		V[find(i)] = 1;
		if (sz[find(i)] > 3) return cout << "-1\n", 0;
		//cout << sz[find(i)] << '\n';
		team[sz[find(i)]].pb(vec[find(i)]);
	}
	//cout << team[3].size() << '\n';
	for (auto i : team[3]) ateam.pb(i);
	if (team[2].size() > team[1].size()) return cout << "-1\n", 0;
	for (int i = 0; i < team[2].size(); i++) {
		vector<int> v;
		v.pb(team[2][i][0]);
		v.pb(team[2][i][1]);
		v.pb(team[1][i][0]);
		ateam.pb(v);
	}
	if ((team[1].size() - team[2].size()) % 3) return cout << "-1\n", 0;
	for (int i = team[2].size(); i < team[1].size(); i += 3) {
		vector<int> v;
		//cout << "AT " << i << '\n';
		v.pb(team[1][i][0]);
		v.pb(team[1][i + 1][0]);
		v.pb(team[1][i + 2][0]);
		ateam.pb(v);
	}
	for (auto i : ateam) {
		for (int j : i) cout << j << ' ';
		cout << '\n';
	}
}