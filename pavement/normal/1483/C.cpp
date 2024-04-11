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

int N, B[300005], H[300005], dp[300005];
stack<int> S;

struct node {
	node *left, *right;
	int S, E, val = -1e17;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = max(val, v);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return -1e17;
		if (l <= S && E <= r) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	root = new node(0, N);
	root->upd(0, 0);
	for (int i = 1; i <= N; i++) {
		while (!S.empty() && H[i] < H[S.top()]) S.pop();
		if (S.empty()) dp[i] = root->qry(0, i - 1) + B[i];
		else dp[i] = max(root->qry(S.top(), i - 1) + B[i], dp[S.top()]);
		root->upd(i, dp[i]);
		S.push(i);
	}
	cout << dp[N] << '\n';
}