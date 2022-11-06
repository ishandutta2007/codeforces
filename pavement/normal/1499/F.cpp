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

int N, K, ans, pdp[5005][5005], prf[5005];
vector<int> adj[5005];
const int MOD = 998244353;

void dp(int n, int e = -1) {
	for (auto u : adj[n])
		if (u != e) dp(u, n);
	for (int i = 0; i <= K; i++) {
		//cout << "COMP " << n << ' ' << i << '\n';
		if (i == 0) {
			pdp[n][i] = 1;
			for (auto u : adj[n])
				if (u != e) pdp[n][i] *= pdp[u][K], pdp[n][i] %= MOD;
		} else {
			int idx = 0, suf = 1;
			prf[0] = 1;
			for (auto u : adj[n]) {
				if (u == e) continue;
				int np = idx + 1;
				prf[np] = prf[idx] * (pdp[u][K] + (min(i - 1, K - i - 1) >= 0 ? pdp[u][min(i - 1, K - i - 1)] : 0));
				prf[np] %= MOD;
				//cout << "PRF " << prf[np] << ' ';
				idx++;
			}
			//cout << '\n';
			for (int j = (int)adj[n].size() - 1; j >= 0; j--) {
				if (adj[n][j] == e) continue;
				idx--;
				//cout << "FIX " << adj[n][j] << ' '<< j << ' ' << prf[idx] << ' ' << ret[adj[n][j]][i - 1] << ' ' << suf << '\n';
				pdp[n][i] += (i - 2 >= 0 ? pdp[adj[n][j]][i - 1] - pdp[adj[n][j]][i - 2] : pdp[adj[n][j]][i - 1]) * prf[idx] % MOD * suf % MOD;
				pdp[n][i] %= MOD;
				int yep = min(i - 2, K - i - 1);
				suf *= pdp[adj[n][j]][K] + (yep >= 0 ? pdp[adj[n][j]][yep] : 0);
				suf %= MOD;
			}
		}
	}
	if (e != -1 && adj[n].size() == 1) pdp[n][0] = 1;
	for (int i = 1; i <= K; i++)
		pdp[n][i] += pdp[n][i - 1], pdp[n][i] %= MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dp(1);
	cout << (pdp[1][K] % MOD + MOD) % MOD << '\n';
}