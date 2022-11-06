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

set<int> S;
map<int, int> tmp;
int N, K, A[35005], dp[55][35005], lst[35005];

struct node {
	node *left, *right;
	int S, E, val, pv;
	node(int _s, int _e) : S(_s), E(_e), val(0), pv(0) {
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
		val = max(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		lst[i] = tmp[A[i]];
		tmp[A[i]] = i;
		S.insert(A[i]);
		dp[1][i] = S.size();
	}
	for (int j = 2; j <= K; j++) {
		root = new node(1, N);
		for (int i = 1; i <= N; i++) {
			// dp[j][i] = max(dp[j - 1][k - 1] + cst(k, i))
			if (lst[i]) root->upd(1, lst[i], -1);
			root->upd(1, i, 1);
			root->upd(i, i, dp[j - 1][i - 1]);
			dp[j][i] = root->val;
		}
	}
	cout << dp[K][N] << '\n';
}