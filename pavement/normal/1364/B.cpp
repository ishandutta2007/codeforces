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

int T, N, P[100005], dp[100005], len[100005], nxt[100005];

struct node {
	node *left, *right;
	int S, E;
	iii val;
	node(int _s, int _e) : S(_s), E(_e) {
		val = mt(-1e9, -1e9, -1e9);
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v, int len, int idx) {
		if (S == E) {
			val = max(val, mt(v, len, idx));
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v, len, idx);
		else right->upd(p, v, len, idx);
		val = max(left->val, right->val);
	}
	iii qry(int l, int r) {
		if (l > E || r < S) return mt(-1e9, -1e9, -1e9);
		if (l <= S && E <= r) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root0, *root1;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		root0 = new node(1, N);
		root1 = new node(1, N);
		for (int i = 1; i <= N; i++) cin >> P[i];
		dp[1] = 0;
		root0->upd(P[1], -P[1], -1, 1);
		root1->upd(P[1], P[1], -1, 1);
		int maxval = dp[1], minlen = 1, curr = 1;
		for (int i = 2; i <= N; i++) {
			iii tmp0 = root0->qry(1, P[i]);
			g0(tmp0) += P[i];
			iii tmp1 = root1->qry(P[i], N);
			g0(tmp1) -= P[i];
			iii tmp = max(tmp0, tmp1);
			dp[i] = g0(tmp);
			len[i] = -g1(tmp) + 1;
			nxt[i] = g2(tmp);
			root0->upd(P[i], -P[i] + dp[i], -len[i], i);
			root1->upd(P[i], P[i] + dp[i], -len[i], i);
			if (dp[i] > maxval) {
				maxval = dp[i];
				minlen = len[i];
				curr = i;
			} else if (dp[i] == maxval && len[i] < minlen) {
				minlen = len[i];
				curr = i;
			}
		}
		vector<int> vec;
		while (nxt[curr]) {
			vec.pb(P[curr]);
			curr = nxt[curr];
		}
		vec.pb(P[1]);
		cout << vec.size() << '\n';
		for (int i = vec.size() - 1; i >= 0; i--) cout << vec[i] << ' ';
		cout << '\n';
	}
}