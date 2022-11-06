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
typedef tree<iii, null_type, greater<iii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, L[100005], R[100005], out[50005];
vector<int> vec[50005];

struct node2 {
	node2 *left, *right;
	int val;
	node2() : left(nullptr), right(nullptr), val(1e9) {}
	void ccleft() {
		if (left != nullptr) return;
		left = new node2();
	}
	void ccright() {
		if (right != nullptr) return;
		right = new node2();
	}
	void upd(int S, int E, int p, int v) {
		val = min(val, v);
		if (S == E) return;
		int M = (S + E) >> 1;
		if (p <= M) ccleft(), left->upd(S, M, p, v);
		else ccright(), right->upd(M + 1, E, p, v);
	}
	int qry(int S, int E, int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && E <= r) return val;
		ccleft();
		ccright();
		int M = (S + E) >> 1;
		return min(left->qry(S, M, l, r), right->qry(M + 1, E, l, r));
	}
};

struct node {
	node *left, *right;
	node2 *val;
	node() : left(nullptr), right(nullptr) {
		val = new node2();
	}
	void ccleft() {
		if (left != nullptr) return;
		left = new node();
	}
	void ccright() {
		if (right != nullptr) return;
		right = new node();
	}
	void upd(int S, int E, int x, int y, int t) {
		val->upd(1, N, y, t);
		if (S == E) return;
		int M = (S + E) >> 1;
		if (x <= M) ccleft(), left->upd(S, M, x, y, t);
		else ccright(), right->upd(M + 1, E, x, y, t);
	}
	int qry(int S, int E, int x1, int x2, int y1, int y2) {
		if (x1 > E || x2 < S) return 1e9;
		if (x1 <= S && E <= x2) return val->qry(1, N, y1, y2);
		ccleft();
		ccright();
		int M = (S + E) >> 1;
		return min(left->qry(S, M, x1, x2, y1, y2), right->qry(M + 1, E, x1, x2, y1, y2));
	}
} *root;

int get(int l, int r) {
	if (l > r) return 0;
	int x = root->qry(1, N, l, r, l, r);
	if (x == 1e9) return 0;
	return get(l, L[x] - 1) + get(R[x] + 1, r) + R[x] - L[x] + 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> L[i] >> R[i];
		vec[R[i] - L[i] + 1].pb(i);
	}
	root = new node();
	for (int i = N; i >= 1; i--) {
		for (int j : vec[i]) root->upd(1, N, L[j], R[j], j);
		out[i] = get(1, N);
	}
	for (int i = 1; i <= N; i++) cout << out[i] << '\n';
}