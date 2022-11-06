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

int N, K, A[35005], dp[2][35005], prv[35005];

struct node {
	node *left, *right;
	int S, E, val, pv;
	node(int _s, int _e) : S(_s), E(_e), pv(0) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val += pv;
		left->pv += pv;
		right->val += pv;
		right->pv += pv;
		pv = 0;
	}
	void reset() {
		val = 1e9;
		prop();
		if (S != E) left->reset(), right->reset();
	}
	void set(int p, int v) {
		if (S == E) {
			val = v;
			return;
		}
		int M = (S + E) >> 1;
		prop();
		if (p <= M) left->set(p, v);
		else right->set(p, v);
		val = min(left->val, right->val);
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val += v;
			pv += v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = min(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(1, N);
	for (int k = 1; k <= K; k++) {
		if (k == 1) {
			for (int i = 1, cst = 0; i <= N; i++) {
				cst += (prv[A[i]] ? i - prv[A[i]] : 0);
				prv[A[i]] = i;
				dp[1][i] = cst;
			}
			continue;
		}
		root->reset();
		for (int i = 1; i <= N; i++) prv[i] = 0;
		for (int i = 1; i <= N; i++) {
			root->set(i, dp[k & 1 ^ 1][i - 1]);
			if (prv[A[i]]) root->upd(1, prv[A[i]], i - prv[A[i]]);
			dp[k & 1][i] = root->val;
			prv[A[i]] = i;
		}
	}
	cout << dp[K & 1][N] << '\n';
}