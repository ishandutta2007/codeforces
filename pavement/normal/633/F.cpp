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

int N, ans, B[100005], tans[200005], mem[200005];
vector<int> adj[100005];
ii ed[200005];

int dp(int k) {
	if (mem[k] != -1) return mem[k];
	int r = B[ed[k].second], fmax = 0, smax = 0;
	for (auto u : adj[ed[k].second])
		if (ed[u].second != ed[k].first) {
			int tmp = max(0ll, dp(u));
			if (tmp >= fmax) {
				smax = fmax;
				fmax = tmp;
			} else if (tmp >= smax) {
				smax = tmp;
			}
			tans[k] = max(tans[k], tans[u]);
		}
	tans[k] = max({tans[k], 0ll, r + fmax + smax});
	return mem[k] = max(0ll, r + fmax);
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		ed[(i<<1) - 1] = mp(u, v);
		ed[i<<1] = mp(v, u);
		adj[u].pb((i<<1) - 1);
		adj[v].pb(i<<1);
	}
	for (int i = 1; i <= 2 * N - 2; i += 2) {
		dp(i);
		dp(i + 1);
		ans = max(ans, tans[i] + tans[i + 1]);
	}
	cout << ans << '\n';
}