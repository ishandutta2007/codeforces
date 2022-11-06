#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

int N, M, H[100005], rev[100005];
vector<int> disc, vec[100005];

iiii combine(iiii a, iiii b) {
	if (g0(a) == -1) return b;
	else if (g0(b) == -1) return a;
	iiii ret = mt(max({g0(a), g0(b), g2(a) + g1(b)}), g1(a), g2(b), g3(a) + g3(b));
	if (g1(a) == g3(a)) g1(ret) = g1(a) + g1(b);
	if (g1(b) == g3(b)) g2(ret) = g1(b) + g2(a);
	return ret;
}

struct node {
	node *left, *right;
	int S, E;
	iiii val;
	node(int _s, int _e, bool _b = 0) : S(_s), E(_e) {
		if (!_b) return;
		if (S == E) {
			val = mt(1ll, 1ll, 1ll, 1ll);
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M, _b);
		right = new node(M + 1, E, _b);
		val = combine(left->val, right->val);
	}
	node *upd(int p) {
		if (S == E) {
			node *ret = new node(S, E);
			ret->val = mt(0ll, 0ll, 0ll, 1ll);
			return ret;
		}
		int M = (S + E) >> 1;
		node *ret = new node(S, E);
		ret->left = left;
		ret->right = right;
		if (p <= M) ret->left = left->upd(p);
		else ret->right = right->upd(p);
		ret->val = combine(ret->left->val, ret->right->val);
		return ret;
	}
	iiii qry(int l, int r) {
		if (l > E || r < S) return mt(-1ll, 0ll, 0ll, 0ll);
		if (l <= S && E <= r) return val;
		return combine(left->qry(l, r), right->qry(l, r));
	}
} *root[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
		disc.pb(H[i]);
	}
	sort(disc.begin(), disc.end());
	disc.erase(unique(disc.begin(), disc.end()), disc.end());
	for (int i = 1; i <= N; i++) {
		int tmp = H[i];
		H[i] = lower_bound(disc.begin(), disc.end(), H[i]) - disc.begin() + 1;
		rev[H[i]] = tmp;
		vec[H[i]].pb(i);
	}
	root[1] = new node(1, N, 1);
	for (int i = 2; i <= N; i++) {
		root[i] = root[i - 1];
		for (int j : vec[i - 1]) root[i] = root[i]->upd(j);
	}
	cin >> M;
	for (int i = 1, l, r, w; i <= M; i++) {
		cin >> l >> r >> w;
		int lo = 1, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (g0(root[mid]->qry(l, r)) >= w) ans = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		cout << rev[ans] << '\n';
	}
}