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

const int MOD = 998244353, B = 400;
bool hv[150005];
int N, Q, idx, inv, root, anc[150005][25], dep[150005], lz[150005], pre[150005], sz[150005], ft[150005];
vector<int> shv, adj[150005];

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r = (r + ft[p]) % MOD;
	return r;
}

void upd(int l, int r, int v) {
	for (; l <= N; l += ls(l)) ft[l] = (ft[l] + v) % MOD;
	for (r++; r <= N; r += ls(r)) ft[r] = (ft[r] - v) % MOD;
}

int dfs(int n, int e = -1) {
	pre[n] = ++idx;
	sz[n] = 1;
	anc[n][0] = e;
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1) anc[n][i] = anc[anc[n][i - 1]][i - 1];
	for (auto u : adj[n]) if (u != e) {
		dep[u] = dep[n] + 1;
		sz[n] += dfs(u, n);
	}
	return sz[n];
}

int nrst(int x, int y) { // y is ancestor of x
	for (int i = 20; i >= 0; i--)
		if (anc[x][i] != -1 && dep[anc[x][i]] > dep[y]) x = anc[x][i];
	return x;
}

main() {
	memset(anc, -1, sizeof anc);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	inv = exp_mod(N, MOD - 2);
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	root = (rng() % N) + 1;
	dfs(root);
	for (int i = 1; i <= N; i++)
		if (adj[i].size() > B) {
			hv[i] = 1;
			shv.pb(i);
		}
	for (int t, v, d; Q--; ) {
		cin >> t;
		if (t == 1) {
			cin >> v >> d;
			upd(pre[v], pre[v] + sz[v] - 1, (N - sz[v]) * d % MOD);
			upd(1, N, sz[v] * d);
			upd(pre[v] + 1, pre[v] + sz[v] - 1, -(sz[v] - 1) * d % MOD);
			if (hv[v]) {
				lz[v] += d;
			} else {
				for (auto u : adj[v]) if (u != anc[v][0])
					upd(pre[u], pre[u] + sz[u] - 1, (sz[v] - 1 - sz[u]) * d);
			}
		} else {
			cin >> v;
			int ret = qry(pre[v]);
			for (auto u : shv)
				if (pre[u] <= pre[v] && pre[v] + sz[v] - 1 <= pre[u] + sz[u] - 1 && u != v) {
					int x = nrst(v, u);
					ret = (ret + (sz[u] - 1 - sz[x]) * lz[u] % MOD) % MOD;
				}
			cout << (ret * inv % MOD + MOD) % MOD << '\n';
		}
	}
}