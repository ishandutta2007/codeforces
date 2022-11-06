#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, A[100005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = A[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return -1e9;
		if (l <= S && r >= E) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

struct node2 {
	node2 *left, *right;
	int S, E, val;
	node2(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = A[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node2(S, M);
		right = new node2(M + 1, E);
		val = min(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && r >= E) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(1, N);
	root2 = new node2(1, N);
	for (int i = 1, L = 1; i <= N; i++) {
		while (L < i && root->qry(L, i) - root2->qry(L, i) > 1)
			L++;
		M = max(M, i - L + 1);
	}
	cout << M << '\n';
}