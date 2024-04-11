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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, K, Q, B[100005];

struct node2 {
	node2 *left, *right;
	int S, E, val;
	node2(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = B[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node2(S, M);
		right = new node2(M + 1, E);
		val = min(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root2;

struct node {
	node *left, *right;
	int S, E, val, pv;
	bool ip;
	node(int _s, int _e) : left(nullptr), right(nullptr), S(_s), E(_e), ip(0) {
		int tmpl = (S - 1) % N + 1, tmpr = (E - 1) % N + 1;
		if (E <= S + N - tmpl) val = root2->qry(tmpl, tmpr);
		else if (E - S < N) val = min(root2->qry(tmpl, N), root2->qry(1, tmpr));
		else val = root2->qry(1, N);
	}
	void prop() {
		if (S == E || !ip) return;
		int M = (S + E) >> 1;
		if (left == nullptr) left = new node(S, M);
		if (right == nullptr) right = new node(M + 1, E);
		left->val = left->pv = right->val = right->pv = val;
		left->ip = right->ip = 1;
		ip = 0;
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			ip = 1;
			val = pv = v;
			return;
		}
		prop();
		int M = (S + E) >> 1;
		if (left == nullptr) left = new node(S, M);
		if (right == nullptr) right = new node(M + 1, E);
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = min(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && E <= r) return val;
		int M = (S + E) >> 1;
		if (left == nullptr) left = new node(S, M);
		if (right == nullptr) right = new node(M + 1, E);
		prop();
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> B[i];
	root2 = new node2(1, N);
	root = new node(1, N * K);
	cin >> Q;
	for (int T, L, R, X; Q--; ) {
		cin >> T;
		if (T == 1) {
			cin >> L >> R >> X;
			root->upd(L, R, X);
		} else {
			cin >> L >> R;
			cout << root->qry(L, R) << '\n';
		}
	}
}