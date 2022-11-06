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
using ordered_set = tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>;

int N, Q, T[200005], X[200005], L[200005], R[200005], dest[200005], nrst[200005], lim[200005], aff[200005];
set<int> ss;
vector<ii> qu;
vector<iii> up, vec[200005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e, int _val = 0) : left(nullptr), right(nullptr), S(_s), E(_e), val(_val) {
		
	}
	node *upd(int p, int v) {
		if (S == E) return new node(S, E, val + v);
		int M = (S + E) >> 1;
		node *ret = new node(S, E);
		if (p <= M) {
			if (left == nullptr) left = new node(S, M);
			ret->right = right;
			ret->left = left->upd(p, v);
			ret->val = (ret->right ? ret->right->val : 0ll) + (ret->left ? ret->left->val : 0ll);
		} else {
			if (right == nullptr) right = new node(M + 1, E);
			ret->right = right->upd(p, v);
			ret->left = left;
			ret->val = (ret->right ? ret->right->val : 0ll) + (ret->left ? ret->left->val : 0ll);
		}
		return ret;
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return val;
		return (left ? left->qry(l, r) : 0ll) + (right ? right->qry(l, r) : 0ll);
	}
} *root[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		ss.insert(i);
		nrst[i] = dest[i] = LLONG_MAX;
	}
	for (int i = 1, t, l, r, x, j; i <= Q; i++) {
		cin >> t;
		if (i == 1) root[i] = new node(1, N);
		else root[i] = root[i - 1];
		if (t == 0) {
			cin >> l >> r >> x;
			if (x == 0) {
				auto it = ss.lower_bound(l);
				vector<set<int>::iterator> tdel;
				while (it != ss.end() && *it <= r) {
					root[i] = root[i]->upd(*it, 1);
					dest[*it] = i;
					tdel.pb(it);
					it++;
				}
				for (auto j : tdel) ss.erase(j);
			} else {
				up.eb(i, l, r);
			}
		} else {
			cin >> j;
			qu.eb(i, j);
		}
		T[i] = t;
		L[i] = l;
		R[i] = r;
		X[i] = x;
	}
	for (auto [i, l, r] : up) {
		int lo = i, hi = Q, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (root[mid]->qry(l, r) == r - l) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		lim[i] = ans;
		if (ans != -1) vec[ans].eb(i, l, r);
	}
	ss.clear();
	for (int i = 1; i <= N; i++) ss.insert(i);
	for (int i = 1; i <= Q; i++) {
		if (T[i] == 0 && X[i] == 0) {
			auto it = ss.lower_bound(L[i]);
			vector<set<int>::iterator> tdel;
			while (it != ss.end() && *it <= R[i]) {
				tdel.pb(it);
				it++;
			}
			for (auto j : tdel) ss.erase(j);
		}
		for (auto [j, l, r] : vec[i]) {
			auto it = ss.lower_bound(l);
			assert(it != ss.end() && *it <= r);
			aff[j] = *it;
		}
	}
	for (int i = 1; i <= Q; i++) {
		if (T[i] == 0 && X[i] == 1)
			nrst[aff[i]] = min(nrst[aff[i]], lim[i]);
	}
	for (auto [i, j] : qu) {
		if (nrst[j] <= i) {
			cout << "YES\n";
		} else {
			if (dest[j] <= i) cout << "NO\n";
			else cout << "N/A\n";
		}
	}
}