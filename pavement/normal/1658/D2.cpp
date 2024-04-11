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

int T, L, R, ans, A[(1 << 17) + 5];

struct node {
	node *left, *right;
	int pos;
	node(int _pos) : left(nullptr), right(nullptr), pos(_pos) {}
	void insert(int x) {
		if (pos == -1) return;
		if (x & (1 << pos)) {
			if (right == nullptr) right = new node(pos - 1);
			right->insert(x);
		} else {
			if (left == nullptr) left = new node(pos - 1);
			left->insert(x);
		}
	}
	int qmin(int x) {
		if (pos == -1) return 0;
		if (x & (1 << pos)) {
			if (right != nullptr) return right->qmin(x);
			else return left->qmin(x) ^ (1 << pos);
		} else {
			if (left != nullptr) return left->qmin(x);
			else return right->qmin(x) ^ (1 << pos);
		}
	}
	int qmax(int x) {
		if (pos == -1) return 0;
		if (!(x & (1 << pos))) {
			if (right != nullptr) return right->qmax(x) ^ (1 << pos);
			else return left->qmax(x);
		} else {
			if (left != nullptr) return left->qmax(x) ^ (1 << pos);
			else return right->qmax(x);
		}
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = -1;
		cin >> L >> R;
		root = new node(17);
		for (int i = 1; i <= R - L + 1; i++) {
			cin >> A[i];
			root->insert(A[i]);
		}
		for (int i = 1; i <= R - L + 1; i++) {
			// try x = A[i] ^ L
			int t1 = root->qmin(A[i] ^ L), t2 = root->qmax(A[i] ^ L);
			if (t1 == L && t2 == R) {
				ans = A[i] ^ L;
				break;
			}
		}
		cout << ans << '\n';
	}
}