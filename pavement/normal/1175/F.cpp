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

int N, ans, A[300005], M[300005];
stack<int> st, st2;

ii combine(ii l, ii r) {
	if (l.first == r.first) return mp(l.first, l.second + r.second);
	return min(l, r);
}

struct node {
	node *left, *right;
	int S, E, pv;
	ii val;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val.first = S - 2 + A[S] * 2;
			val.second = 1;
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = combine(left->val, right->val);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val.first += pv;
		right->val.first += pv;
		left->pv += pv;
		right->pv += pv;
		pv = 0;
	}
	ii qry(int l, int r) {
		if (l > E || r < S) return mp((int)1e16, -1ll);
		if (l <= S && E <= r) return val;
		prop();
		return combine(left->qry(l, r), right->qry(l, r));
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
		val = combine(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(1, N);
	for (int i = 1, L = 0; i <= N; i++) {
		L = max(L, M[A[i]]);
		M[A[i]] = i;
		while (!st.empty() && A[st.top()] <= A[i]) {
			int tmp = st.top();
			st.pop();
			root->upd((st.empty() ? 1 : st.top() + 1), tmp, A[i] - A[tmp]);
		}
		st.push(i);
		while (!st2.empty() && A[st2.top()] >= A[i]) {
			int tmp = st2.top();
			st2.pop();
			root->upd((st2.empty() ? 1 : st2.top() + 1), tmp, A[i] - A[tmp]);
		}
		st2.push(i);
		root->upd(1, N, -1);
		auto res = root->qry(L + 1, i);
		if (res.first == 0) ans += res.second;
	}
	cout << ans << '\n';
}