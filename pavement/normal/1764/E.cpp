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

int tc, n, k, a[100005], b[100005], sf[100005], v[100005];
iii t[100005];

struct node {
	node *left, *right;
	int S, E, val, pv;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val = v[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = max(left->val, right->val);
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
		if (l > r) return;
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val += v;
			pv += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > r) return -1;
		if (S == E) return (val > 0 ? S : -1);
		prop();
		if (right->val > 0) return right->qry(l, r);
		else return left->qry(l, r);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
		}
		if (n == 1) {
			cout << (k <= a[1] ? "YES" : "NO") << '\n';
			continue;
		}
		if (k <= a[1]) {
			cout << "YES\n";
			continue;
		}
		// k - b[1] <= y <= a[1]
		int pt = k - b[1];
		if (pt > a[1]) {
			cout << "NO\n";
			continue;
		}
		bool can = 0;
		
		for (int i = 2; i <= n; i++) {
			t[i - 1] = mt(a[i] + b[i], a[i], b[i]);
		}
		
		sort(t + 1, t + n);
		
		for (int i = 1, useless; i <= n - 1; i++) {
			tie(useless, a[i], b[i]) = t[i];
			
		}
		
		for (int i = n - 1, _sf = 0; i >= 1; i--) {
			v[i] = (pt - _sf - a[i] - b[i]);
			_sf += b[i];
			sf[i] = _sf;
		}
		//~ cout << '.' << endl;
		root = new node(1, n - 1);
		//~ cout << '.' << endl;
		for (int i = 1; i <= n - 1; i++) {
			root->upd(1, i - 1, b[i]);
			//~ cout << '.' << endl;
			int tmp_1 = root->qry(1, i - 1);
			int tmp_2 = root->qry(i + 1, n - 1);
			//~ cout << '!' << endl;
			int tmp = max({0ll, tmp_1, tmp_2});
			if (pt - (sf[tmp + 1] - (i > tmp ? b[i] : 0)) <= a[i]) can = 1;
			root->upd(1, i - 1, -b[i]);
		}
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
}