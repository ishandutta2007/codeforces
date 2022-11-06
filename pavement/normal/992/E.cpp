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

int N, Q, A[200005], P[200005];
stack<ii> stk;

struct node {
	node *left, *right;
	int S, E, pv;
	ii val;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val = mp(A[S] - P[S], S);
			return;
		}
		int M = (S + E) / 2;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = max(left->val, right->val);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val.first += pv;
		left->pv += pv;
		right->val.first += pv;
		right->pv += pv;
		pv = 0;
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val.first += v;
			pv += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = max(left->val, right->val);
	}
	void pupd(int p, int v) {
		if (S == E) {
			val = mp(v, S);
			return;
		}
		prop();
		int M = (S + E) / 2;
		if (p <= M) left->pupd(p, v);
		else right->pupd(p, v);
		val = max(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		P[i] = P[i - 1] + A[i - 1];
	}
	root = new node(1, N);
	for (int i = 1, p, x; i <= Q; i++) {
		cin >> p >> x;
		root->upd(p + 1, N, A[p] - x);
		root->upd(p, p, x - A[p]);
		A[p] = x;
		int ans = -1;
		while (root->val.first >= 0) {
			//cout << "@ " << root->val.second << ' ' << root->val.first << '\n';
			if (root->val.first == 0) {
				ans = root->val.second;
				break;
			}
			stk.emplace(root->val);
			root->pupd(root->val.second, -1e16);
			//cout << "@ " << root->val.second << ' ' << root->val.first << '\n';
		}
		while (!stk.empty()) {
			auto j = stk.top();
			root->pupd(j.second, j.first);
			stk.pop();
		}
		cout << ans << '\n';
	}
}