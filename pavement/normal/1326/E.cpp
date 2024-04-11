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

int N, Q, P[300005], pos[300005];

struct node {
	node *left, *right;
	int S, E, val, sff;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = -(S == pos[N]);
			sff = val;
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = left->val + right->val;
		sff = min(right->sff, right->val + left->sff);
	}
	void upd(int p, int v) {
		if (S == E) {
			val += v;
			sff = min(0ll, val);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = left->val + right->val;
		sff = min(right->sff, right->val + left->sff);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		pos[P[i]] = i;
	}
	root = new node(1, N);
	cout << N << ' ';
	for (int i = 1, curr = N; i < N; i++) {
		cin >> Q;
		root->upd(Q, 1);
		while (root->sff == 0) root->upd(pos[--curr], -1);
		cout << curr << ' ';
	}
	cout << '\n';
}