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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, A[100005], ans[100005];
set<int> S;

struct node {
	node *left, *right;
	int S, E, mx, pv;
	ii val;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val = mp(A[S], S);
			mx = A[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = min(left->val, right->val);
		mx = max(left->mx, right->mx);
	}
	void prop() {
		if (S == E || !pv) return;
		left->pv += pv;
		left->mx += pv;
		left->val.first += pv;
		right->pv += pv;
		right->mx += pv;
		right->val.first += pv;
		pv = 0;
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val.first += v;
			mx += v;
			pv += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = min(left->val, right->val);
		mx = max(left->mx, right->mx);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return LLONG_MIN;
		if (l <= S && E <= r) return mx;
		prop();
		return max(left->qry(l, r), right->qry(l, r));
	}
	void del(int p) {
		if (S == E) {
			val = mp((int)1e15, -1ll);
			mx = LLONG_MIN;
			return;
		}
		prop();
		int M = (S + E) >> 1;
		if (p <= M) left->del(p);
		else right->del(p);
		val = min(left->val, right->val);
		mx = max(left->mx, right->mx);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		S.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			S.insert(i);
			ans[i] = 1;
		}
		root = new node(1, N);
		while (1) {
			auto [m, idx] = root->val;
			if (idx == -1) break;
			int tmp = root->qry(1, idx - 1);
			if (tmp > m) {
				auto it = S.lower_bound(tmp - m);
				assert(it != S.end());
				int op = *it;
				S.erase(it);
				ans[op] = idx;
				//~ cout << "UPD " << idx << ' ' << op << '\n';
				root->upd(idx, N, op);
			}
			//~ cout << "DEL " << idx << '\n';
			root->del(idx);
		}
		for (int i = 1; i <= N; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}