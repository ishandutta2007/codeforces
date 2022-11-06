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

int N, Q, small[3], big[3];
char c, S[200005];
ordered_set<int> pos[3];

struct node {
	node *left, *right;
	int S, E, pv;
	ii val;
	void combine() {
		if (left->val.first == right->val.first) val = mp(left->val.first, left->val.second + right->val.second);
		else val = max(left->val, right->val);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val.first += pv;
		left->pv += pv;
		right->val.first += pv;
		right->pv += pv;
		pv = 0;
	}
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) {
			val = mp(0, 1);
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		combine();
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
		combine();
	}
} *root;

int ans() {
	int ret = 0;
	for (int k = 0; k < 3; k++) {
		if (pos[k].empty()) continue;
		vector<ii> ranges;
		int ss = (pos[small[k]].empty() ? N + 1 : *pos[small[k]].begin());
		int bb = (pos[big[k]].empty() ? N + 1 : *pos[big[k]].begin());
		ranges.eb(1, min(ss, bb) - 1);
		ranges.eb(ss, N);
		ss = (pos[small[k]].empty() ? 0 : *pos[small[k]].rbegin());
		bb = (pos[big[k]].empty() ? 0 : *pos[big[k]].rbegin());
		ranges.eb(max(ss, bb) + 1, N);
		ranges.eb(1, ss);
		for (auto [l, r] : ranges) {
			// cout << "RR " << l << ' ' << r << ' ' << k << '\n';
			if (l <= r) {
				int tl = pos[k].order_of_key(l), tr = (int)pos[k].order_of_key(r + 1) - 1;
				// [tl, tr]
				// cout << tl << ' ' << tr << '\n';
				if (tl <= tr) root->upd(tl, tr, 1);
			}
		}
		// cout << "! ! " << root->val.first << ' ' << root->val.second << '\n';
		if (root->val.first == 2) ret += root->val.second;
		for (auto [l, r] : ranges)
			if (l <= r) {
				int tl = pos[k].order_of_key(l), tr = (int)pos[k].order_of_key(r + 1) - 1;
				// [tl, tr]
				if (tl <= tr) root->upd(tl, tr, -1);
			}
	}
	return ret;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < 3; i++) {
		small[i] = (i + 1) % 3;
		big[i] = (i - 1 + 3) % 3;
	}
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		if (S[i] == 'R') S[i] = 0;
		else if (S[i] == 'S') S[i] = 1;
		else S[i] = 2;
		pos[S[i]].insert(i);
	}
	root = new node(0, N - 1);
	cout << ans() << '\n';
	for (int i = 1, p; i <= Q; i++) {
		cin >> p >> c;
		if (c == 'R') c = 0;
		else if (c == 'S') c = 1;
		else c = 2;
		pos[S[p]].erase(p);
		S[p] = c;
		pos[S[p]].insert(p);
		cout << ans() << '\n';
	}
}