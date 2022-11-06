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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, M, Q, idx, lnk[300005], sz[300005], pre[300005], dep[300005], rep[300005], anc[300005][25];
vector<int> adj[300005];

struct node {
	node *left, *right;
	int S, E;
	ii val_1, val_2;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val_1 = val_2 = mp(pre[S], S);
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val_1 = min(left->val_1, right->val_1);
		val_2 = max(left->val_2, right->val_2);
	}
	pair<ii, ii> qry(int l, int r) {
		if (l > E || r < S) return mp(mp((int)1e16, -1ll), mp((int)-1e16, -1ll));
		if (l <= S && E <= r) return mp(val_1, val_2);
		auto lr = left->qry(l, r), rr = right->qry(l, r);
		return mp(min(lr.first, rr.first), max(lr.second, rr.second));
	}
} *root;

int find(int x) {
	if (x == lnk[x]) return x;
	return lnk[x] = find(lnk[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	lnk[b] = a;
}

void dfs(int n) {
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1) anc[n][i] = anc[anc[n][i - 1]][i - 1];
	pre[n] = ++idx;
	for (auto u : adj[n]) {
		anc[u][0] = n;
		dep[u] = dep[n] + 1;
		dfs(u);
	}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int k = 20; k >= 0; k--)
		if (dep[v] - (1 << k) >= dep[u]) {
			v = anc[v][k];
		}
	if (u == v) return u;
	for (int k = 20; k >= 0; k--)
		if (anc[u][k] != anc[v][k]) {
			u = anc[u][k];
			v = anc[v][k];
		}
	return anc[u][0];
}

main() {
	memset(anc, -1, sizeof anc);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M >> Q;
		for (int i = 1; i <= N; i++) {
			lnk[i] = rep[i] = i;
			sz[i] = 1;
		}
		for (int i = 1, u, v; i <= M; i++) {
			cin >> u >> v;
			u = find(u);
			v = find(v);
			if (rep[u] != rep[v]) {
				adj[i + N].pb(rep[u]);
				adj[i + N].pb(rep[v]);
			} else {
				adj[i + N].pb(rep[u]);
			}
			unite(u, v);
			rep[find(u)] = i + N;
		}
		dfs(N + M);
		root = new node(1, N + M);
		for (int l, r; Q--; ) {
			cin >> l >> r;
			auto ret = root->qry(l, r);
			int sm = ret.first.second, la = ret.second.second;
			cout << max(0ll, lca(sm, la) - N) << ' ';
		}
		cout << '\n';
		idx = 0;
		for (int i = 1; i <= N + M; i++) {
			adj[i].clear();
			dep[i] = pre[i] = 0;
			for (int k = 0; k <= 20; k++) anc[i][k] = -1;
		}
	}
}