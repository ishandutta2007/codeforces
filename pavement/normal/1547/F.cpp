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

int Q, N, a[200005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = a[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = __gcd(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return val;
		return __gcd(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> a[i];
		root = new node(1, N);
		int lo = 1, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			set<int> ss;
			for (int i = 1; i <= N; i++) {
				if (i + mid - 1 <= N) ss.insert(root->qry(i, i + mid - 1));
				else ss.insert(__gcd(root->qry(i, N), root->qry(1, mid - (N - i + 1))));
			}
			if (ss.size() == 1) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		cout << ans - 1 << '\n';
	}
}