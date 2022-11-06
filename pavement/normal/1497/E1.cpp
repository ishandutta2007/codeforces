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

int T, N, K, A[200005], prv[200005], dp[200005], sp[10000005];
map<vector<int>, int> yep;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = prv[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

void test_case() {
	yep.clear();
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		prv[i] = dp[i] = 0;
		cin >> A[i];
		int curr = -1, occ = 0;
		vector<int> vec;
		while (A[i] != 1) {
			if (sp[A[i]] != curr) {
				if (occ % 2) vec.pb(curr);
				curr = sp[A[i]];
				occ = 0;
			}
			occ++;
			A[i] /= sp[A[i]];
		}
		if (occ % 2) vec.pb(curr);
		if (yep.find(vec) != yep.end()) prv[i] = yep[vec];
		yep[vec] = i;
	}
	root = new node(1, N);
	int slid = 1;
	for (int i = 1; i <= N; i++) {
		while (root->qry(slid, i) >= slid) slid++;
		dp[i] = dp[slid - 1] + 1;
	}
	cout << dp[N] << '\n';
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 1e7; i++) sp[i] = i;
	for (int i = 2; i <= 1e7; i++)
		if (sp[i] == i) {
			for (int j = i + i; j <= 1e7; j += i)
				if (sp[j] == j) sp[j] = i;
		}
	cin >> T;
	while (T--) test_case();
}