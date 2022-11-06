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

int N, M, A[100005];

struct node {
	node *left, *right;
	int S, E, sum, mx;
	node(int _s, int _e) : S(_s), E(_e), sum(0), mx(0) {
		if (S == E) {
			sum = mx = A[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		sum = left->sum + right->sum;
		mx = max(left->mx, right->mx);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return sum;
		return left->qry(l, r) + right->qry(l, r);
	}
	void mod(int l, int r, int x) {
		if (l > E || r < S || mx < x) return;
		if (S == E) {
			sum %= x;
			mx %= x;
			return;
		}
		left->mod(l, r, x);
		right->mod(l, r, x);
		sum = left->sum + right->sum;
		mx = max(left->mx, right->mx);
	}
	void set(int p, int v) {
		if (S == E) {
			sum = mx = v;
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->set(p, v);
		else right->set(p, v);
		sum = left->sum + right->sum;
		mx = max(left->mx, right->mx);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(1, N);
	for (int t, l, r, k, x; M--; ) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r;
			cout << root->qry(l, r) << '\n';
		} else if (t == 2) {
			cin >> l >> r >> x;
			root->mod(l, r, x);
		} else {
			cin >> k >> x;
			root->set(k, x);
		}
	}
}