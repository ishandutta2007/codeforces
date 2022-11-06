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

int n, T, k, x, lastans;

struct node {
	node *left, *right;
	int S, E, val, val2, pv;
	node(int _s, int _e) : left(nullptr), right(nullptr), S(_s), E(_e), val(S), val2(E), pv(0) {}
	void cc() {
		if (S == E || left != nullptr) return;
		int M = (S + E) / 2;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val += pv;
		left->val2 += pv;
		left->pv += pv;
		right->val += pv;
		right->val2 += pv;
		right->pv += pv;
		pv = 0;
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val += v;
			val2 += v;
			pv += v;
			return;
		}
		cc();
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = min(left->val, right->val);
		val2 = max(left->val2, right->val2);
	}
	int qry(int p) {
		if (S == E) {
			assert(val == val2);
			return val;
		}
		int M = (S + E) / 2;
		cc();
		prop();
		if (p <= M) return left->qry(p);
		else return right->qry(p);
	}
	int qryl(int p) {
		if (S == E) {
			assert(val == val2 && val == p);
			return S;
		}
		cc();
		prop();
		if (p <= left->val2) return left->qryl(p);
		else return right->qryl(p);
	}
	int qryr(int p) {
		if (S == E) {
			assert(val == val2 && val == p);
			return S;
		}
		cc();
		prop();
		if (p >= right->val) return right->qryr(p);
		else return left->qryr(p);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	root = new node(0, 1e9);
	for (int i = 1; i <= n; i++) {
		cin >> T >> k;
		int ll = root->qry(0), rr = root->qry(1e9);
		if (ll <= T && T <= rr) {
			int x = root->qryl(T), y = root->qryr(T);
			root->upd(0, x - 1, 1);
			root->upd(y + 1, 1e9, -1);
		} else if (T < ll) {
			root->upd(0, 1e9, -1);
		} else {
			root->upd(0, 1e9, 1);
		}
		for (int j = 0; j < k; j++) {
			cin >> x;
			x = (x + lastans) % (int)(1e9 + 1);
			cout << (lastans = root->qry(x)) << '\n';
		}
	}
}