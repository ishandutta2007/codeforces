#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

int N, K, dp[300005], to[300005];
ii ans, A[300005];

struct node {
	node *left, *right;
	ii val;
	node() : left(nullptr), right(nullptr), val(0, 0) {}
	void ccleft() {
		if (left != nullptr) return;
		left = new node();
	}
	void ccright() {
		if (right != nullptr) return;
		right = new node();
	}
	void upd(int p, int v, int idx, int pos = 30) {
		val = max(val, mp(v, idx));
		if (pos == -1) return;
		if (p & (1 << pos)) ccright(), right->upd(p, v, idx, pos - 1);
		else ccleft(), left->upd(p, v, idx, pos - 1);
	}
	ii qry(int p, int pos = 30) {
		if (pos == -1) return val;
		if (!(K & (1 << pos))) {
			if (!(p & (1 << pos))) {
				//cout << right->val << '\n';
				return ccleft(), max(right == nullptr ? mp(0, 0) : right->val, left->qry(p, pos - 1));
			} else {
				//cout << left->val << '\n';
				return ccright(), max(left == nullptr ? mp(0, 0) : left->val, right->qry(p, pos - 1));
			}
		} else {
			if (p & (1ll << pos)) return ccleft(), left->qry(p, pos - 1);
			else return ccright(), right->qry(p, pos - 1);
		}
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	root = new node();
	sort(A + 1, A + 1 + N);
	for (int i = 1; i <= N; i++) {
		ii tmp = root->qry(A[i].first);
		dp[i] = tmp.first + 1;
		to[i] = tmp.second;
		ans = max(ans, mp(dp[i], i));
		root->upd(A[i].first, dp[i], i);
		//cout << dp[i] << ' ';
	}
	if (ans.first == 1) cout << "-1\n";
	else {
		cout << ans.first << '\n';
		for (int j = ans.second; j; j = to[j]) cout << A[j].second << ' ';
		cout << '\n';
	}
}