// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct node {
	int l, r, val;
	node(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}
};

vector<node> nodes;

int build_tree(int l, int r) {
	if (l + 1 == r) {
		nodes.push_back(node(-1, -1, -1));
		return szof(nodes) - 1;
	}
	int m = (l + r) / 2;
	int lv = build_tree(l, m);
	int rv = build_tree(m, r);
	nodes.push_back(node(lv, rv, -1));
	return szof(nodes) - 1;
}

int n;

int segtree_get(int rt, int pos) {
	int l = 0, r = n;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (pos < m) {
			rt = nodes[rt].l;
			r = m;
		} else {
			rt = nodes[rt].r;
			l = m;
		}
	}
	return nodes[rt].val;
}

int segtree_set(int rt, int pos, int val) {
	// cerr << "set " << rt << " " << pos << " " << val << endl;
	int l = 0, r = n;
	int ret = szof(nodes);
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (pos < m) {
			nodes.push_back(node(szof(nodes) + 1, nodes[rt].r, -1));
			rt = nodes[rt].l;
			r = m;
		} else {
			nodes.push_back(node(nodes[rt].l, szof(nodes) + 1, -1));
			rt = nodes[rt].r;
			l = m;
		}
	}
	nodes.push_back(node(-1, -1, val));
	return ret;
}

// void rec_print_tree(int v) {
// 	if (nodes[v].l != -1) {
// 		rec_print_tree(nodes[v].l);
// 	}
// 	cerr << nodes[v].val << " ";
// 	if (nodes[v].r != -1) {
// 		rec_print_tree(nodes[v].r);
// 	}
// }

// void print_tree(int v) {
// 	rec_print_tree(v);
// 	cerr << endl;
// }

void solve() {
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		arr.push_back(num);
	}

	nodes.clear();
	int root = build_tree(0, n);
	// print_tree(root);
	vector<int> roots(n + 1);
	roots[n] = root;

	vector<int> depth(n + 1);

	ll ans = 0;

	for (int i = n - 1; i >= 0; --i) {
		int pos = segtree_get(roots[i + 1], arr[i]);
		// cerr << i << " " << pos << endl;
		if (pos != -1) {
			depth[i] = depth[pos + 1] + 1;
			++pos;
		} else {
			depth[i] = 0;
			pos = n;
		}
		roots[i] = segtree_set(roots[pos], arr[i], i);
		ans += depth[i];
		// print_tree(roots[i]);
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}