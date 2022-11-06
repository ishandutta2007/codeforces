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

int N, Q, id, idx, st, md = -1, dep[2][500005], pre[2][500005], rev[500005], sz[2][500005], u[500005], v[500005], w[500005];
bool dist[500005];
vector<ii> adj[500005];

void dfs(int n, int e = -1, int d = 0) {
	if (d > md) {
		md = d;
		st = n;
	}
	for (auto u : adj[n])
		if (u.first != e) dfs(u.first, n, d + 1);
}

int rt(int n, int t, int e = -1) {
	pre[t][n] = ++idx;
	rev[idx] = n;
	sz[t][n] = 1;
	for (auto u : adj[n])
		if (u.first != e) {
			dep[t][u.first] = dep[t][n] + 1;
			dist[u.first] = dist[n] ^ u.second;
			sz[t][n] += rt(u.first, t, n);
		}
	return sz[t][n];
}

struct node {
	node *left, *right;
	int S, E, val[2];
	bool pv;
	node(int _s, int _e, int t) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val[dist[rev[S]]] = dep[t][rev[S]];
			val[!dist[rev[S]]] = -1;
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M, t);
		right = new node(M + 1, E, t);
		val[0] = max(left->val[0], right->val[0]);
		val[1] = max(left->val[1], right->val[1]);
	}
	void prop() {
		if (S == E || !pv) return;
		swap(left->val[0], left->val[1]);
		left->pv ^= 1;
		swap(right->val[0], right->val[1]);
		right->pv ^= 1;
		pv = 0;
	}
	void upd(int l, int r) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			swap(val[0], val[1]);
			pv ^= 1;
			return;
		}
		prop();
		left->upd(l, r);
		right->upd(l, r);
		val[0] = max(left->val[0], right->val[0]);
		val[1] = max(left->val[1], right->val[1]);
	}
} *root1, *root2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].eb(v[i], w[i]);
		adj[v[i]].eb(u[i], w[i]);
	}
	dfs(1);
	md = -1;
	int frnt = st;
	dfs(st);
	rt(frnt, 0);
	root1 = new node(1, N, 0);
	idx = 0;
	dist[st] = 0;
	rt(st, 1);
	root2 = new node(1, N, 1);
	cin >> Q;
	while (Q--) {
		cin >> id;
		if (dep[0][u[id]] < dep[0][v[id]]) swap(u[id], v[id]);
		root1->upd(pre[0][u[id]], pre[0][u[id]] + sz[0][u[id]] - 1);
		if (dep[1][u[id]] < dep[1][v[id]]) swap(u[id], v[id]);
		root2->upd(pre[1][u[id]], pre[1][u[id]] + sz[1][u[id]] - 1);
		cout << max(root1->val[0], root2->val[0]) << '\n';
	}
}