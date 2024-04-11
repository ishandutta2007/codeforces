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
typedef long double ld;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, cc, link[200005], sz[200005], cnt[200005];
bool V[200005], bad[200005];
pair<int, int> edg[200005];

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
	bad[a] |= bad[b];
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
	for (int u, v, i = 1; i <= M; i++) {
		cin >> u >> v;
		cnt[u]++;
		cnt[v]++;
		edg[i] = mp(u, v);
	}
	for (int i = 1; i <= M; i++) {
		unite(edg[i].first, edg[i].second);
		if (cnt[edg[i].first] != 2 || cnt[edg[i].second] != 2) bad[find(edg[i].first)] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (V[find(i)]) continue;
		V[find(i)] = 1;
		cc += sz[find(i)] > 1 && !bad[find(i)];
	}
	cout << cc << '\n';
}