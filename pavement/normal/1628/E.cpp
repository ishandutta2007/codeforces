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

int N, Q, idx, anc[600005][25], dep[600005], link[600005], sz[600005], rep[600005], pre[600005], wei[600005], rev[600005];
vector<int> adj[600005];
iii ed[600005];

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[v] - (1 << i) >= dep[u]) v = anc[v][i];
	if (u == v) return v;
	for (int i = 20; i >= 0; i--)
		if (anc[u][i] != -1 && anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

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

void dfs(int n, int e = -1) {
	anc[n][0] = e;
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1) anc[n][i] = anc[anc[n][i - 1]][i - 1];
	pre[n] = ++idx;
	rev[idx] = n;
	for (auto u : adj[n]) if (u != e) {
		dep[u] = dep[n] + 1;
		dfs(u, n);
	}
}

struct node {
	node *left, *right;
	int S, E, val, val2, fval, fval2;
	bool ip, pv;
	node(int _s, int _e) : S(_s), E(_e), val(1e9), val2(-1e9), ip(0), pv(0) {
		if (S == E) {
			fval = fval2 = pre[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		fval = min(left->fval, right->fval);
		fval2 = max(left->fval2, right->fval2);
	}
	void prop() {
		if (S == E || !ip) return;
		if (pv) {
			left->val = left->fval;
			left->val2 = left->fval2;
			right->val = right->fval;
			right->val2 = right->fval2;
		} else {
			left->val = right->val = 1e9;
			left->val2 = right->val2 = -1e9;
		}
		left->ip = right->ip = 1;
		left->pv = right->pv = pv;
		ip = 0;
	}
	void upd(int l, int r, bool v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			if (v) val = fval, val2 = fval2;
			else val = 1e9, val2 = -1e9;
			ip = 1;
			pv = v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = min(left->val, right->val);
		val2 = max(left->val2, right->val2);
	}
} *root;

main() {
	memset(anc, -1, sizeof anc);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1, u, v, w; i < N; i++) {
		cin >> u >> v >> w;
		ed[i] = mt(w, u, v);
	}
	for (int i = 1; i <= N; i++) {
		link[i] = rep[i] = i;
		sz[i] = 1;
	}
	sort(ed + 1, ed + N);
	for (int i = 1, u, v, w; i < N; i++) {
		tie(w, u, v) = ed[i];
		int ru = rep[find(u)], rv = rep[find(v)];
		if (ru == rv) adj[i + N].pb(ru);
		else adj[i + N].pb(ru), adj[i + N].pb(rv);
		unite(u, v);
		wei[i + N] = w;
		rep[find(u)] = i + N;
	}
	dfs(2 * N - 1);
	root = new node(1, N);
	for (int i = 1, t, l, r, x; i <= Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r;
			root->upd(l, r, 1);
		} else if (t == 2) {
			cin >> l >> r;
			root->upd(l, r, 0);
		} else {
			cin >> x;
			ii tmp = mp(root->val, root->val2);
			tmp.first = min(tmp.first, pre[x]);
			tmp.second = max(tmp.second, pre[x]);
			int tmp2 = lca(rev[tmp.first], rev[tmp.second]);
			if (N < tmp2) cout << wei[tmp2] << '\n';
			else cout << "-1\n";
		}
	}
}