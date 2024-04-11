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

int N, M, cnt[10005], col[10005], dep[10005], down[10005], down2[10005], link[10005], prved[10005], sz[10005], tt[10005], tt2[10005], up[10005], up2[10005];
bool vis[10005], yes[10005];
vector<int> ans, vec, nadj[10005];
vector<ii> adj[10005];

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

void init(int n, int prv = -1) {
	prved[n] = prv;
	for (auto u : adj[n])
		if (dep[u.first] == -1) {
			dep[u.first] = dep[n] + 1;
			nadj[n].pb(u.first);
			col[u.first] = col[n] ^ 1;
			init(u.first, u.second);
		} else if (u.second != prv && dep[u.first] < dep[n]) {
			if (col[u.first] == col[n]) {
				yes[u.second] = 1;
				up[n]++;
				down[u.first]++;
				cnt[find(n)]++;
			} else {
				up2[n]++;
				down2[u.first]++;
			}
		}
}

int dp(int n) {
	if (tt[n] != -1) return tt[n];
	tt[n] = up[n] - down[n];
	for (auto u : nadj[n])
		tt[n] += dp(u);
	return tt[n];
}

int dp2(int n) {
	if (tt2[n] != -1) return tt2[n];
	tt2[n] = up2[n] - down2[n];
	for (auto u : nadj[n])
		tt2[n] += dp2(u);
	return tt2[n];
}

main() {
	memset(dep, -1, sizeof dep);
	memset(tt, -1, sizeof tt);
	memset(tt2, -1, sizeof tt2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		link[i] = i;
		sz[i] = 1;
	}
	for (int u, v, i = 1; i <= M; i++) {
		cin >> u >> v;
		unite(u, v);
		adj[u].eb(v, i);
		adj[v].eb(u, i);
	}
	for (int i = 1; i <= N; i++)
		if (dep[i] == -1) dep[i] = 0, init(i);
	for (int i = 1; i <= N; i++) {
		if (vis[find(i)]) continue;
		vis[find(i)] = 1;
		if (cnt[find(i)] > 0) vec.pb(find(i));
	}
	if (vec.size() == 0) {
		cout << M << '\n';
		for (int i = 1; i <= M; i++) cout << i << ' ';
		return cout << '\n', 0;
	}
	if (vec.size() > 1) return cout << "0\n", 0;
	if (cnt[vec[0]] == 1)
		for (int i = 1; i <= M; i++)
			if (yes[i]) ans.pb(i);
	for (int i = 1; i <= N; i++)
		if (find(i) == vec[0] && dp(i) == cnt[vec[0]] && dp2(i) == 0) ans.pb(prved[i]);
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i : ans) cout << i << ' ';
	cout << '\n';
}