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

int N, ans, A[200005];

struct node {
	node *left, *right;
	int pos, cnt;
	node(int _pos) : left(nullptr), right(nullptr), pos(_pos), cnt(0) {}
	void insert(int x) {
		cnt++;
		if (pos == -1) return;
		if (x & (1 << pos)) {
			if (right == nullptr) right = new node(pos - 1);
			right->insert(x);
		} else {
			if (left == nullptr) left = new node(pos - 1);
			left->insert(x);
		}
	}
	void remove(int x) {
		cnt--;
		if (pos == -1) return;
		if (x & (1 << pos)) right->remove(x);
		else left->remove(x);
	}
	int qry(int x) {
		if (pos == -1) return 0;
		if (x & (1 << pos)) {
			if (right != nullptr && right->cnt) return right->qry(x);
			else return left->qry(x) | (1 << pos);
		} else {
			if (left != nullptr && left->cnt) return left->qry(x);
			else return right->qry(x) | (1 << pos);
		}
	}
} *root;

void rec(int p, vector<int> &vec) {
	if (vec.empty() || p == -1) return;
	vector<int> zv, ov;
	for (int i : vec)
		if (A[i] & (1 << p)) ov.pb(i);
		else zv.pb(i);
	if (!ov.empty() && !zv.empty()) {
		int curr = LLONG_MAX;
		for (int i : ov) root->insert(A[i]);
		for (int i : zv) curr = min(curr, root->qry(A[i]));
		for (int i : ov) root->remove(A[i]);
		ans += curr;
	}
	rec(p - 1, zv);
	rec(p - 1, ov);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	vector<int> vec;
	for (int i = 1; i <= N; i++) vec.pb(i);
	root = new node(29);
	rec(29, vec);
	cout << ans << '\n';
}