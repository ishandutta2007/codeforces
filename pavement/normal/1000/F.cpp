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

int N, Q, A[500005], M[500005], out[500005];
vector<ii> vec[500005];

struct node {
	node *left, *right;
	int S, E;
	ii val;
	node(int _s, int _e) : S(_s), E(_e), val((int)1e16, -1ll) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = mp(v, S);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = min(left->val, right->val);
	}
	void del(int p) {
		if (S == E) {
			val = mp((int)1e16, -1ll);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->del(p);
		else right->del(p);
		val = min(left->val, right->val);
	}
	ii qry(int l, int r) {
		if (l > E || r < S) return mp((int)1e16, -1ll);
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(1, N);
	cin >> Q;
	for (int l, r, i = 1; i <= Q; i++) {
		cin >> l >> r;
		vec[r].eb(l, i);
	}
	root = new node(1, N);
	for (int i = 1; i <= N; i++) {
		if (M[A[i]]) root->del(M[A[i]]);
		root->upd(i, M[A[i]]);
		M[A[i]] = i;
		for (auto j : vec[i]) {
			auto res = root->qry(j.first, i);
			if (res.first < j.first) out[j.second] = res.second;
		}
	}
	for (int i = 1; i <= Q; i++) cout << A[out[i]] << '\n';
}