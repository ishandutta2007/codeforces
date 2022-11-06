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

int N, Q, A[300005], out[300005], ft[300005];
vector<ii> vec[300005];

inline int ls(int x) { return x & -x; }

void ft_upd(int p) {
	for (; p <= N; p += ls(p)) ft[p]++;
}

int ft_qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

struct node {
	node *left, *right;
	int S, E, pv;
	ii val;
	node(int _s, int _e) : S(_s), E(_e), pv(0), val((int)1e9, -1ll) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val.first += pv;
		left->pv += pv;
		right->val.first += pv;
		right->pv += pv;
		pv = 0;
	}
	void upd(int p, int v) {
		if (S == E) {
			val = mp(v, -S);
			return;
		}
		prop();
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = min(left->val, right->val);
	}
	void add(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val.first += v;
			pv += v;
			return;
		}
		prop();
		left->add(l, r, v);
		right->add(l, r, v);
		val = min(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1, x, y; i <= Q; i++) {
		cin >> x >> y;
		x++;
		y = N - y;
		vec[x].eb(y, i);
	}
	root = new node(1, N);
	for (int i = N; i >= 1; i--) {
		if (A[i] <= i) root->upd(i, i - A[i]);
		while (root->val.first == 0) {
			int x = -root->val.second;
			ft_upd(x);
			root->add(x + 1, N, -1);
			root->upd(x, (int)1e9);
		}
		for (auto [j, idx] : vec[i]) out[idx] = ft_qry(j);
	}
	for (int i = 1; i <= Q; i++) cout << out[i] << '\n';
}