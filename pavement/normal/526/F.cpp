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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int N, ans, A[300005];
stack<int> maxstk, minstk;

struct node {
	node *left, *right;
	int S, E, pv;
	ii val;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		val = mp(1ll, E - S + 1);
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void combine() {
		if (left->val.first == right->val.first) val = mp(left->val.first, left->val.second + right->val.second);
		else val = min(left->val, right->val);
	}
	void prop() {
		if (S == E || !pv) return;
		left->pv += pv;
		right->pv += pv;
		left->val.first += pv;
		right->val.first += pv;
		pv = 0;
	}
	void upd(int l, int r, int v) {
		if (l > r || l > E || r < S) return;
		if (l <= S && E <= r) {
			val.first += v;
			pv += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		combine();
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, x, y; i <= N; i++) {
		cin >> x >> y;
		A[x] = y;
	}
	root = new node(1, N);
	for (int i = 1; i <= N; i++) {
		while (!maxstk.empty()) {
			int x = maxstk.top();
			if (A[x] > A[i]) break;
			maxstk.pop();
			root->upd((maxstk.empty() ? 0 : maxstk.top()) + 1, x, A[i] - A[x]);
		}
		maxstk.push(i);
		while (!minstk.empty()) {
			int x = minstk.top();
			if (A[x] < A[i]) break;
			minstk.pop();
			root->upd((minstk.empty() ? 0 : minstk.top()) + 1, x, A[x] - A[i]);
		}
		minstk.push(i);
		root->upd(1, i, -1);
		ans += root->val.second;
	}
	cout << ans << '\n';
}