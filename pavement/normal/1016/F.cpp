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

int N, M, ans, idx, dist1[300005], dist2[300005], lr[300005], ord[300005], par[300005], rr[300005];
ii P[300005];
vector<ii> adj[300005];
queue<ii> Q;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e), val(-1e17) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = v;
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return -1e17;
		if (l <= S && E <= r) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

void dfs1(int n, int e = -1) {
	for (auto u : adj[n])
		if (u.first ^ e) {
			par[u.first] = n;
			if (!lr[n]) lr[n] = rr[n] = ord[u.first];
			else lr[n] = min(lr[n], ord[u.first]), rr[n] = max(rr[n], ord[u.first]);
			dist1[u.first] = dist1[n] + u.second;
			dfs1(u.first, n);
		}
}

void dfs2(int n, int e = -1) {
	for (auto u : adj[n])
		if (u.first ^ e) {
			dist2[u.first] = dist2[n] + u.second;
			dfs2(u.first, n);
		}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1, u, v, w; i < N; i++) {
		cin >> u >> v >> w;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}
	Q.emplace(1, -1);
	for (ii x; !Q.empty(); ) {
		x = Q.front();
		Q.pop();
		ord[x.first] = ++idx;
		for (auto u : adj[x.first])
			if (u.first ^ x.second)
				Q.emplace(u.first, x.first);
	}
	dfs1(1);
	dfs2(N);
	for (int i = 1; i <= N; i++)
		P[i] = mp(dist1[i] - dist2[i], i);
	sort(P + 1, P + 1 + N, greater<ii>());
	root = new node(1, N);
	for (int i = 1; i <= N; i++) {
		int now = -1e17;
		if (!lr[P[i].second]) { // no children
			if (ord[par[P[i].second]] == 1) now = root->qry(2, N);
			else if (ord[par[P[i].second]] == N) now = root->qry(1, N - 1);
			else now = max(root->qry(1, ord[par[P[i].second]] - 1), root->qry(ord[par[P[i].second]] + 1, N));
		} else {
			vector<ii> seg, aseg;
			if (lr[P[i].second] > 1) seg.eb(1, lr[P[i].second] - 1);
			if (rr[P[i].second] < N) seg.eb(rr[P[i].second] + 1, N);
			for (auto j : seg)
				if (j.first <= ord[par[P[i].second]] && ord[par[P[i].second]] <= j.second) {
					if (j.first < ord[par[P[i].second]]) aseg.eb(j.first, ord[par[P[i].second]] - 1);
					if (ord[par[P[i].second]] < j.second) aseg.eb(ord[par[P[i].second]] + 1, j.second);
				} else aseg.pb(j);
			for (auto j : aseg) now = max(now, root->qry(j.first, j.second));
		}
		ans = max(ans, now + dist1[P[i].second]);
		root->upd(ord[P[i].second], dist2[P[i].second]);
	}
	for (int X; M--; ) {
		cin >> X;
		cout << min(dist1[N], ans + X) << '\n';
	}
}