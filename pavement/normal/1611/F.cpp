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

int T, N, S, A[200005], P[200005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = P[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = min(left->val, right->val);
	}	
	int qry(int l, int r) {
		if (l > E || r < S) return LLONG_MAX;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

bool valid(int l, int r) {
	// for all l <= i <= r,
	// P[i] - P[l - 1] >= -S
	// P[i] >= -S + P[l - 1]
	int x = root->qry(l, r);
	return x >= -S + P[l - 1];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> S;
		for (int i = 1; i <= N; i++) cin >> A[i], P[i] = P[i - 1] + A[i];
		root = new node(1, N);
		int st = 1;
		iii ans = mt(0ll, -1ll, -1ll);
		for (int i = 1; i <= N; i++) {
			while (st <= i && !valid(st, i)) st++;
			ans = max(ans, mt(i - st + 1, st, i));
		}
		if (g0(ans) == 0) cout << "-1\n";
		else cout << g1(ans) << ' ' << g2(ans) << '\n';
	}
}