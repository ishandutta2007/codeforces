#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
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
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, L[200005], R[200005], D[800005];
iii T[800005];

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = D[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = min(left->val, right->val);
	}	
	int qry(int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, idx = 0; i <= N; i++) {
		cin >> L[i] >> R[i];
		T[++idx] = mt(L[i], i, 1);
		T[++idx] = mt(L[i] + 1, -1, -1);
		T[++idx] = mt(R[i], i, 0);
		T[++idx] = mt(R[i] + 1, -1, -1);
	}
	sort(T + 1, T + 1 + 4 * N);
	g0(T[0]) = -1;
	for (int i = 1, cnt = 0; i <= 4 * N; i++) {
		if (g0(T[i]) != g0(T[i - 1])) cnt++;
		if (g2(T[i]) == 1) L[g1(T[i])] = cnt;
		else if (!g2(T[i])) R[g1(T[i])] = cnt;
	}
	for (int i = 1; i <= N; i++) {
		D[L[i]]++;
		D[R[i] + 1]--;
	}
	for (int i = 1; i <= 4 * N; i++) D[i] += D[i - 1];
	root = new node(1, 4 * N);
	for (int i = 1; i <= N; i++)
		if (root->qry(L[i], R[i]) > 1) return cout << i << '\n', 0;
	cout << "-1\n";
}