#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
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

int N, M, A[100005];

struct node {
	node *left, *right;
	int S, E, val;
	bool ip;
	node(int _s, int _e, int _ty) : S(_s), E(_e), ip(0) {
		if (S == E) {
			val = !!(A[S] & (1 << _ty));
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M, _ty);
		right = new node(M + 1, E, _ty);
		val = left->val + right->val;
	}
	void prop() {
		if (S == E || !ip) return;
		left->val = (left->E - left->S + 1) - left->val;
		right->val = (right->E - right->S + 1) - right->val;
		left->ip ^= 1;
		right->ip ^= 1;
		ip = 0;
	}
	void upd(int l, int r) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val = (E - S + 1) - val;
			ip ^= 1;
			return;
		}
		prop();
		left->upd(l, r);
		right->upd(l, r);
		val = left->val + right->val;
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return val;
		prop();
		return left->qry(l, r) + right->qry(l, r);
	}
} *root[25];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 0; i <= 20; i++) root[i] = new node(1, N, i);
	cin >> M;
	for (int T, L, R, X; M--; ) {
		cin >> T;
		if (T == 1) {
			cin >> L >> R;
			ll Y = 0;
			for (int i = 0; i <= 20; i++)
				Y += (ll)root[i]->qry(L, R) * (ll)(1 << i);
			cout << Y << '\n';
		} else {
			cin >> L >> R >> X;
			for (int i = 0; i <= 20; i++)
				if (X & (1 << i)) root[i]->upd(L, R);
		}
	}
}