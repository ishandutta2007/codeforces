#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
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
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, K, tans, A[500005], disc[500005], dp[500005];
bool H[500005];
vector<int> vec, vec2, vec3;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e), val(1e15) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e15;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
	void upd(int p, int v) {
		if (S == E) {
			val = min(val, v);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = min(left->val, right->val);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1, B; i <= K; i++) cin >> B, H[B] = 1, vec3.pb(B);
	for (int j = 1; j < vec3.size(); j++)
		if (A[vec3[j]] - vec3[j] < A[vec3[j - 1]] - vec3[j - 1]) return cout << "-1\n", 0;
	for (int i = 1; i <= N; i++) {
		if (H[i]) {
			if (vec.empty()) continue;
			vec2.clear();
			for (int j : vec) vec2.pb(A[j] - j);
			sort(vec2.begin(), vec2.end());
			for (int j : vec) disc[j] = lower_bound(vec2.begin(), vec2.end(), A[j] - j) - vec2.begin() + 1;
			root = new node(1, vec.size());
			for (int j : vec) {
				dp[j] = root->qry(1, disc[j]) + j - 1;
				if (A[j] - j >= (vec[0] == 1 ? -1e15 : A[vec[0] - 1] - (vec[0] - 1))) dp[j] = min(dp[j], j - (vec[0] - 1) - 1);
				root->upd(disc[j], dp[j] - j);
			}
			int curans = i - vec[0];
			for (int j : vec)
				if (A[j] - j <= A[i] - i) curans = min(curans, dp[j] + i - j - 1);
			tans += curans;
			vec.clear();
		} else vec.pb(i);
	}
	if (!vec.empty()) {
		vec2.clear();
		for (int j : vec) vec2.pb(A[j] - j);
		sort(vec2.begin(), vec2.end());
		for (int j : vec) disc[j] = lower_bound(vec2.begin(), vec2.end(), A[j] - j) - vec2.begin() + 1;
		root = new node(1, vec.size());
		for (int j : vec) {
			dp[j] = root->qry(1, disc[j]) + j - 1;
			if (A[j] - j >= (vec[0] == 1 ? -1e15 : A[vec[0] - 1] - (vec[0] - 1))) dp[j] = min(dp[j], j - (vec[0] - 1) - 1);
			root->upd(disc[j], dp[j] - j);
		}
		int curans = N + 1 - vec[0];
		for (int j : vec)
			curans = min(curans, dp[j] + N - j);
		tans += curans;
		vec.clear();
	}
	cout << tans << '\n';
}