#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, ans, cnt, pres[500005], succ[500005];
char S[500005];
vector<ii> vec;
stack<int> stk;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = -1;
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = -1;
	}
	void upd(int p, int v) {
		if (S == E) {
			val = max(val, v);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S || l > r) return -1;
		if (l <= S && E <= r) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

struct node2 {
	node2 *left, *right;
	int S, E, val;
	node2(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = 1e9;
			return;
		}
		int M = (S + E) >> 1;
		left = new node2(S, M);
		right = new node2(M + 1, E);
		val = 1e9;
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
	int qry(int l, int r) {
		if (l > E || r < S || l > r) return 1e9;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N; i++) {
		if (S[i] == '1') {
			cnt++;
		} else if (cnt) {
			vec.eb(i - cnt, cnt);
			cnt = 0;
		}
	}
	if (cnt) vec.eb(N - cnt + 1, cnt);
	if (vec.size() == 0) return cout << "0\n", 0;
	for (int i = 0; i < vec.size(); i++) {
		while (!stk.empty() && vec[stk.top()].second < vec[i].second) stk.pp();
		if (stk.empty()) pres[i] = -1;
		else pres[i] = stk.top();
		stk.push(i);
	}
	while (!stk.empty()) stk.pp();
	for (int i = (int)vec.size() - 1; i >= 0; i--) {
		while (!stk.empty() && vec[stk.top()].second <= vec[i].second) stk.pp();
		if (stk.empty()) succ[i] = -1;
		else succ[i] = stk.top();
		stk.push(i);
	}
	for (int i = 0; i < vec.size(); i++) {
		int lef, rig;
		if (pres[i] == -1) lef = 1;
		else lef = vec[pres[i]].first + vec[pres[i]].second + 1 - vec[i].second;
		if (succ[i] == -1) rig = N;
		else rig = vec[succ[i]].first + vec[i].second - 1;
		ans += (vec[i].first - lef + 1) * (rig - (vec[i].first + vec[i].second - 1) + 1) * vec[i].second;
		//cout << "FULL " << i << ' ' << lef << ' ' << rig << '\n';
	}
	root = new node(0, N);
	root2 = new node2(0, N);
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 1; j < vec[i].second; j++) {
			int x = root->qry(j, N);
			int lef = (x == -1 ? 1 : vec[x].first + vec[x].second - j + 1);
			//cout << "P " << i << ' ' << j << ' ' << lef << ' ' << vec[i].first + j - 1 << '\n';
			ans += (vec[i].first - lef + 1) * j;
		}
		root->upd(vec[i].second, i);
	}
	for (int i = (int)vec.size() - 1; i >= 0; i--) {
		for (int j = 1; j < vec[i].second; j++) {
			int x = root2->qry(j + 1, N);
			int lef = vec[i].first + vec[i].second - j;
			int rig = (x == 1e9 ? N : vec[x].first + j - 1);
			//cout << "S " << i << ' ' << j << ' ' << lef << ' ' << rig << '\n';
			ans += (rig - (vec[i].first + vec[i].second - 1) + 1) * j;
		}
		root2->upd(vec[i].second, i);
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 1; j <= vec[i].second; j++)
			for (int k = vec[i].first + 1; k + j - 1 < vec[i].first + vec[i].second - 1; k++)
				ans += j;
	}
	cout << ans << '\n';
}