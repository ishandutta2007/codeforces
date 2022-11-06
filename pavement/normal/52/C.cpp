#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define getchar_unlocked _getchar_nolock
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

int N, M, A[200005];

struct node {
	node *left, *right;
	int S, E, val, pv;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val = A[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = min(left->val, right->val);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val += pv;
		left->pv += pv;
		right->val += pv;
		right->pv += pv;
		pv = 0;
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
	int qry(int l, int r) {
		if (l > E || r < S) return 1e16;
		if (l <= S && E <= r) return val;
		prop();
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

bool read(int &v) {
	bool neg = 0;
	v = 0;
	char ch = getchar_unlocked();
	while (ch != '-' && ('0' > ch || ch > '9')) ch = getchar_unlocked();
	if (ch == '-') {
		neg = 1;
		ch = getchar_unlocked();
	}
	while ('0' <= ch && ch <= '9') {
		v = (v << 3) + (v << 1) + (ch & 15);
		ch = getchar_unlocked();
	}
	if (neg) v = -v;
	return ch == '\n';
}

main() {
	read(N);
	for (int i = 0; i < N; i++) read(A[i]);
	root = new node(0, N - 1);
	read(M);
	for (int L, R, V; M--; ) {
		read(L);
		if (read(R)) {
			if (L > R) printf("%lld\n", min(root->qry(L, N - 1), root->qry(0, R)));
			else printf("%lld\n", root->qry(L, R));
		} else {
			assert(read(V));
			if (L > R) {
				root->upd(L, N - 1, V);
				root->upd(0, R, V);
			} else root->upd(L, R, V);
		}
	}
}