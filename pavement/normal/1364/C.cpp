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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, A[100005], lst[100005], out[100005];
vector<ii> vec[100005];

struct node {
	node *left, *right;
	int S, E, val = -1;
	bool set = 0, ip = 0;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !ip) return;
		if (!left->set) {
			left->val = val;
			left->set = left->ip = 1;
		}
		if (!right->set) {
			right->val = val;
			right->set = right->ip = 1;
		}
		ip = 0;
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			if (set) return;
			set = ip = 1;
			val = v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
	}
	int qry(int p) {
		if (S == E) return val;
		prop();
		int M = (S + E) >> 1;
		if (p <= M) return left->qry(p);
		else return right->qry(p);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	root = new node(0, 1e6);
	int maxval = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		maxval = max(maxval, A[i]);
		lst[A[i]] = i;
		root->upd(0, A[i] - 1, i);
	}
	root->upd(0, 1e6, N + 1);
	bool no = 0;
	for (int i = 0; i <= maxval; i++) { // change later
		int lft = lst[i] + 1, rig = root->qry(i);
		if (lft > rig) {
			no = 1;
			break;
		}
		vec[lft].eb(rig, i);
	}
	if (no) return cout << "-1\n", 0;
	set<ii> S;
	for (int i = 1; i <= N; i++) {
		for (auto j : vec[i])
			S.insert(j);
		if (S.empty()) out[i] = 1e6;
		else {
			out[i] = S.begin()->second;
			S.erase(S.begin());
		}
		if (S.size() && S.begin()->first <= i) {
			no = 1;
			break;
		}
	}
	if (no) return cout << "-1\n", 0;
	for (int i = 1; i <= N; i++) cout << out[i] << ' ';
	cout << '\n';
}