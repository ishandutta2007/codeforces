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

int N, Q, idx, dep[100005], pre[100005], sz[100005], anc[100005][25];
vector<int> adj[100005];

int dfs(int n) {
	pre[n] = ++idx;
	sz[n] = 1;
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1)
			anc[n][i] = anc[anc[n][i - 1]][i - 1];
	for (auto u : adj[n]) {
		anc[u][0] = n;
		dep[u] = dep[n] + 1;
		sz[n] += dfs(u);
	}
	return sz[n];
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[u] - (1<<i) >= dep[v])
			u = anc[u][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
		if (anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

int k_anc(int n, int k) {
	for (int i = 0; k > 0; i++, k >>= 1)
		if (k & 1) n = anc[n][i];
	return n;
}

struct node {
	int S, E, val;
	node *left, *right;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = S;
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = lca(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return -1;
		if (l <= S && r >= E) return val;
		int lq = left->qry(l, r), rq = right->qry(l, r);
		if (lq != -1 && rq != -1) return lca(lq, rq);
		else if (lq == -1) return rq;
		else return lq;
	}
} *root;

struct node2 {
	int S, E, mi, ma, miidx, maidx;
	node2 *left, *right;
	node2(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			mi = ma = pre[S];
			miidx = maidx = S;
			return;
		}
		int M = (S + E) >> 1;
		left = new node2(S, M);
		right = new node2(M + 1, E);
		if (left->mi <= right->mi) {
			mi = left->mi;
			miidx = left->miidx;
		} else {
			mi = right->mi;
			miidx = right->miidx;
		}
		if (left->ma >= right->ma) {
			ma = left->ma;
			maidx = left->maidx;
		} else {
			ma = right->ma;
			maidx = right->maidx;
		}
	}
	ii min_qry(int l, int r) {
		if (l > E || r < S) return mp(1e9, -1);
		if (l <= S && r >= E) return mp(mi, miidx);
		return min(left->min_qry(l, r), right->min_qry(l, r));
	}
	ii max_qry(int l, int r) {
		if (l > E || r < S) return mp(-1e9, -1);
		if (l <= S && r >= E) return mp(ma, maidx);
		return max(left->max_qry(l, r), right->max_qry(l, r));
	}
} *root2;

main() {
	memset(anc, -1, sizeof anc);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 2, P; i <= N; i++) {
		cin >> P;
		adj[P].pb(i);
	}
	dfs(1);
	root = new node(1, N);
	root2 = new node2(1, N);
	for (int L, R; Q--; ) {
		cin >> L >> R;
		int W = root->qry(L, R);
		if (L <= W && W <= R) {
			cout << W << ' ';
			if (L < W && W < R) cout << dep[lca(root->qry(L, W - 1), root->qry(W + 1, R))];
			else if (L == W) cout << dep[root->qry(W + 1, R)];
			else cout << dep[root->qry(L, W - 1)];
			cout << '\n';
		} else {
			ii ml = root2->min_qry(L, R), mr = root2->max_qry(L, R), ans = mp(-1, -1);
			// look at L
			int tmp1 = k_anc(L, dep[L] - dep[W] - 1);
			if (ml.first < pre[tmp1]) {
				// try ml.second
				int mdep;
				if (L < ml.second && ml.second < R) mdep = dep[lca(root->qry(L, ml.second - 1), root->qry(ml.second + 1, R))];
				else if (L == ml.second) mdep = dep[root->qry(ml.second + 1, R)];
				else mdep = dep[root->qry(L, ml.second - 1)];
				ans = max(ans, mp(mdep, ml.second));
			} else {
				// try mr.second
				int mdep;
				if (L < mr.second && mr.second < R) mdep = dep[lca(root->qry(L, mr.second - 1), root->qry(mr.second + 1, R))];
				else if (L == mr.second) mdep = dep[root->qry(mr.second + 1, R)];
				else mdep = dep[root->qry(L, mr.second - 1)];
				ans = max(ans, mp(mdep, mr.second));
			}
			// look at R
			tmp1 = k_anc(R, dep[R] - dep[W] - 1);
			if (ml.first < pre[tmp1]) {
				// try ml.second
				int mdep;
				if (L < ml.second && ml.second < R) mdep = dep[lca(root->qry(L, ml.second - 1), root->qry(ml.second + 1, R))];
				else if (L == ml.second) mdep = dep[root->qry(ml.second + 1, R)];
				else mdep = dep[root->qry(L, ml.second - 1)];
				ans = max(ans, mp(mdep, ml.second));
			} else {
				// try mr.second
				int mdep;
				if (L < mr.second && mr.second < R) mdep = dep[lca(root->qry(L, mr.second - 1), root->qry(mr.second + 1, R))];
				else if (L == mr.second) mdep = dep[root->qry(mr.second + 1, R)];
				else mdep = dep[root->qry(L, mr.second - 1)];
				ans = max(ans, mp(mdep, mr.second));
			}
			cout << ans.second << ' ' << ans.first << '\n';
		}
	}
}