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
typedef long double ld;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, Q, ch, A[500005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = A[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = __gcd(left->val, right->val);
	}
	void cnt(int l, int r, int x) {
		if (l > E || r < S) return;
		if (l <= S && r >= E) {
			if (val % x == 0) return;
			ch += S == E;
			if (S == E) return;
		}
		left->cnt(l, r, x);
		if (ch >= 2) return;
		right->cnt(l, r, x);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = v;
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = __gcd(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(1, N);
	cin >> Q;
	for (int t, l, r, x; Q--; ) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> x;
			ch = 0;
			root->cnt(l, r, x);
			cout << (ch < 2 ? "YES" : "NO") << '\n';
		} else {
			cin >> l >> r;
			root->upd(l, r);
		}
	}
}