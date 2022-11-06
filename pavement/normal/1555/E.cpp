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

int N, M, ans, l[300005], r[300005], w[300005];
iii t[300005];

struct node {
	node *left, *right;
	int S, E, val, pv;
	node(int _s, int _e) : S(_s), E(_e), val(0), pv(0) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !pv) return;
		left->pv += pv;
		left->val += pv;
		right->pv += pv;
		right->val += pv;
		pv = 0;
	}
	int qry(int l, int r) {
		if (l > E || r < S) return LLONG_MAX;
		if (l <= S && E <= r) return val;
		prop();
		return min(left->qry(l, r), right->qry(l, r));
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			pv += v;
			val += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = min(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ans = LLONG_MAX;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> l[i] >> r[i] >> w[i];
		t[i] = mt(w[i], l[i], r[i]);
	}
	sort(t + 1, t + 1 + N);
	for (int i = 1; i <= N; i++) tie(w[i], l[i], r[i]) = t[i];
	root = new node(1, M - 1);
	for (int i = N, rpt = N; i >= 1; i--) {
		root->upd(l[i], r[i] - 1, 1);
		while (i < rpt && root->qry(l[rpt], r[rpt] - 1) > 1) {
			root->upd(l[rpt], r[rpt] - 1, -1);
			rpt--;
		}
		if (root->qry(1, M - 1)) ans = min(ans, w[rpt] - w[i]);
	}
	cout << ans << '\n';
}