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

int N, X, T, P[100005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e), val(1e9) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = min(val, v);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = min(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> X;
		root = new node(0, X);
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			P[i] += P[i - 1];
			P[i] %= X;
		}
		root->upd(0, 0);
		int total = -1;
		for (int i = 1; i <= N; i++) {
			int ans = 1e9;
			if (P[i]) ans = min(ans, root->qry(0, P[i] - 1));
			ans = min(ans, root->qry(P[i] + 1, X));
			if (ans < 1e9) total = max(total, i - ans);
			root->upd(P[i], i);
		}
		cout << total << '\n';
	}
}