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

const int B = 1200;
bool done[100005];
int N, K, idx, up[100005], out[100005], chc[100005], ord[100005], par[100005], lab[100005];
ii dp[100005];
vector<int> adj[100005], chd[100005];

void dfs(int n, int e = -1) {
	for (auto u : adj[n]) if (u != e) dfs(u, n);
	lab[n] = ++idx;
	ord[idx] = n;
	par[n] = e;
}

int f(int k) {
	if (done[k]) return chc[k];
	for (int i = 1; i <= N; i++) {
		int r1 = 0, fmax = 0, smax = 0;
		ii t1, t2;
		for (auto u : chd[i]) {
			ii tmp = dp[u];
			r1 += tmp.first;
			if (tmp.second >= fmax) {
				smax = fmax;
				fmax = tmp.second;
			} else if (tmp.second >= smax) smax = tmp.second;
		}
		if (fmax + 1 == k) t1 = mp(r1 + 1, 0);
		else t1 = mp(r1, fmax + 1);
		if (fmax + smax + 1 >= k) t2 = mp(r1 + 1, 0);
		dp[i] = max(t1, t2);
	}
	done[k] = 1;
	return chc[k] = dp[N].first;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    for (int i = 1; i <= N; i++)
		for (auto u : adj[i])
			if (u != par[i]) chd[lab[i]].pb(lab[u]);
	for (int i = 1; i <= min(N, B); i++) out[i] = f(i);
	int prv = B;
	for (int i = N / B; i >= 0; i--) {
		int lo = prv + 1, hi = N, ans = -1;
		bool seen = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2, res = f(mid);
			if (res >= i) {
				if (res == i) seen = 1;
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (seen) up[i] = ans;
		prv = ans;
	}
    for (int i = N / B, prv = B; i >= 0; i--) {
        for (int j = prv + 1; j <= up[i]; j++) out[j] = i;
        prv = max(prv, up[i]);
    }
    for (int i = 1; i <= N; i++) cout << out[i] << '\n';
}