#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, Q;
char S[100005];

struct node {
	node *left, *right;
	int S, E, val;
	bool ip, pv;
	node(int _s, int _e) : S(_s), E(_e), val(0), ip(0) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !ip) return;
		left->ip = right->ip = 1;
		left->pv = right->pv = pv;
		left->val = (left->E - left->S + 1) * pv;
		right->val = (right->E - right->S + 1) * pv;
		ip = 0;
	}
	void upd(int l, int r, bool v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val = (E - S + 1) * v;
			pv = v;
			ip = 1;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = left->val + right->val;
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return val;
		prop();
		return left->qry(l, r) + right->qry(l, r);
	}
} *root[26];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int k = 0; k < 26; k++) root[k] = new node(1, N);
	for (int i = 1; i <= N; i++)
		root[S[i] - 'a']->upd(i, i, 1);
	for (int l, r, t, curr, i = 1; i <= Q; i++) {
		cin >> l >> r >> t;
		vector<ii> tmp;
		for (int x, k = 0; k < 26; k++) {
			x = root[k]->qry(l, r);
			if (x) tmp.eb(k, x);
			root[k]->upd(l, r, 0);
		}
		if (!t) reverse(tmp.begin(), tmp.end());
		curr = l;
		for (auto j : tmp)
			root[j.first]->upd(curr, curr + j.second - 1, 1), curr += j.second;
	}
	for (int i = 1; i <= N; i++)
		for (int k = 0; k < 26; k++)
			if (root[k]->qry(i, i)) {
				cout << char(k + 'a');
				break;
			}
}