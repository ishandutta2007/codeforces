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

int T, N, A[250005], dist[250005], lim[250005], lim2[250005];
stack<int> S, S2;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e), val(1e16) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			val += v;
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = min(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e16;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root, *root2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		while (!S.empty()) S.pop();
		while (!S2.empty()) S2.pop();
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = N; i >= 1; i--) {
			while (!S.empty() && A[S.top()] > A[i]) S.pop();
			if (S.empty()) lim[i] = N + 1;
			else lim[i] = S.top();
			S.push(i);
			while (!S2.empty() && A[S2.top()] < A[i]) S2.pop();
			if (S2.empty()) lim2[i] = N + 1;
			else lim2[i] = S2.top();
			S2.push(i);
		}
		dist[N] = 0;
		while (!S.empty()) S.pop();
		while (!S2.empty()) S2.pop();
		root = new node(1, N);
		root2 = new node(1, N);
		root->upd(N, -(int)1e16);
		S.push(N);
		root2->upd(N, -(int)1e16);
		S2.push(N);
		for (int i = N - 1; i >= 0; i--) {
			while (!S.empty() && A[S.top()] < A[i]) {
				root->upd(S.top(), (int)1e16);
				S.pop();
			}
			while (!S2.empty() && A[S2.top()] > A[i]) {
				root2->upd(S2.top(), (int)1e16);
				S2.pop();
			}
			dist[i] = 1 + min(root->qry(i, lim[i] - 1), root2->qry(i, lim2[i] - 1));
			root->upd(i, dist[i] - (int)1e16);
			S.push(i);
			root2->upd(i, dist[i] - (int)1e16);
			S2.push(i);
		}
		cout << dist[1] << '\n';
	}
}