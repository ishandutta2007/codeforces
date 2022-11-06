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

int N, Q, P[120005], ans[120005];
stack<int> S, T;
vector<ii> qu[120005];

struct node {
	node *left, *right;
	int S, E, pv, tv, val, ans, mincnt;
	node(int _s, int _e) : S(_s), E(_e), pv(0), tv(0), val(0), ans(0), mincnt(E - S + 1) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || (!tv && !pv)) return;
		left->val += pv;
		left->pv += pv;
		right->val += pv;
		right->pv += pv;
		if (left->val == val) {
			left->tv += tv;
			left->ans += tv * left->mincnt;
		}
		if (right->val == val) {
			right->tv += tv;
			right->ans += tv * right->mincnt;
		}
		tv = pv = 0;
	}
	void combine() {
		val = min(left->val, right->val);
		mincnt = 0;
		for (node *i : {left, right})
			if (i->val == val) mincnt += i->mincnt;
		ans = left->ans + right->ans;
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
		combine();
	}
	int qry_val(int p) {
		if (S == E) return val;
		int M = (S + E) >> 1;
		prop();
		if (p <= M) return left->qry_val(p);
		else return right->qry_val(p);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return ans;
		prop();
		return left->qry(l, r) + right->qry(l, r);
	}
	void fupd(int l, int r) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			tv += 1;
			ans += mincnt;
			return;
		}
		prop();
		left->fupd(l, r);
		right->fupd(l, r);
		combine();
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	root = new node(1, N);
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		root->upd(i, i, i - 1);
	}
	cin >> Q;
	for (int i = 1, l, r; i <= Q; i++) {
		cin >> l >> r;
		qu[r].eb(l, i);
	}
	for (int i = 1; i <= N; i++) {
		root->upd(1, N, -1);
		while (!S.empty() && P[S.top()] < P[i]) {
			int x = S.top();
			S.pop();
			root->upd(S.empty() ? 1 : S.top() + 1, x, P[i] - P[x]);
		}
		S.push(i);
		while (!T.empty() && P[T.top()] > P[i]) {
			int x = T.top();
			T.pop();
			root->upd(T.empty() ? 1 : T.top() + 1, x, P[x] - P[i]);
		}
		T.push(i);
		root->fupd(1, N);
		for (auto j : qu[i])
			ans[j.second] = root->qry(j.first, i);
	}
	for (int i = 1; i <= Q; i++) cout << ans[i] << '\n';
}