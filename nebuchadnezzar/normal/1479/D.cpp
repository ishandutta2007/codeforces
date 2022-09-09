// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

const int P = 2;
vector<int> pp;

struct node {
	int l, r, val;
	node() : l(-1), r(-1), val(0) {}
	node(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}
};

vector<node> segtree;
int bpv;

int segtree_change(int v, int pos) {
	int ret = szof(segtree);
	int vl = 0, vr = bpv;
	while (vr - vl > 1) {
		int vm = (vl + vr) / 2;
		if (pos < vm) {
			segtree.push_back(node(szof(segtree) + 1, segtree[v].r, 0));
			v = segtree[v].l;
			vr = vm;
		} else {
			segtree.push_back(node(segtree[v].l, szof(segtree) + 1, 0));
			v = segtree[v].r;
			vl = vm;
		}
	}
	segtree.push_back(node(-1, -1, segtree[v].val ^ 1));
	for (int i = szof(segtree) - 2, len = 1; i >= ret; --i, len *= 2) {
		int l = segtree[i].l;
		int r = segtree[i].r;
		segtree[i].val = sum(mult(segtree[l].val, pp[len]), segtree[r].val);
	}
	return ret;
}

int segtree_find_odd(int v1, int v2, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return -1;
	}
	if (l <= vl && vr <= r) {
		if (segtree[v1].val == segtree[v2].val) {
			return -1;
		}
		if (vl + 1 == vr) {
			return vl;
		}
	}
	int vm = (vl + vr) / 2;
	int ret = segtree_find_odd(segtree[v1].l, segtree[v2].l, vl, vm, l, r);
	if (ret != -1) {
		return ret;
	}
	return segtree_find_odd(segtree[v1].r, segtree[v2].r, vm, vr, l, r);
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		arr.push_back(num);
	}

	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int bp = 1;
	while (1 << bp < n) {
		++bp;
	}

	vector<int> depth(n);
	vector<vector<int>> binup(n, vector<int>(bp));
	vector<int> tin(n), tout(n);
	vector<int> seq;
	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		depth[v] = d;
		binup[v][0] = p;
		for (int i = 1; i < bp; ++i) {
			binup[v][i] = binup[binup[v][i - 1]][i - 1];
		}

		tin[v] = szof(seq);
		seq.push_back(arr[v]);

		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v, d + 1);
			}
		}

		tout[v] = szof(seq);
		seq.push_back(arr[v]);
	};

	dfs(0, 0, 0);

	auto get_lca = [&](int a, int b) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[b] - (1 << i) >= depth[a]) {
				b = binup[b][i];
			}
		}
		if (a == b) {
			return a;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (binup[a][i] != binup[b][i]) {
				a = binup[a][i];
				b = binup[b][i];
			}
		}
		return binup[a][0];
	};

	bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	pp.push_back(1);
	for (int i = 0; i < bpv + 5; ++i) {
		pp.push_back(mult(pp.back(), P));
	}

	segtree.resize(bpv * 2);
	for (int i = 1; i < bpv; ++i) {
		segtree[i].l = i * 2;
		segtree[i].r = i * 2 + 1;
	}

	vector<int> roots = {1};

	for (int i = 0; i < szof(seq); ++i) {
		roots.push_back(segtree_change(roots.back(), seq[i]));
	}

	auto find_odd = [&](int from, int to, int l, int r) {
		int r1 = roots[from], r2 = roots[to];
		return segtree_find_odd(r1, r2, 0, bpv, l, r);
	};

	for (int i = 0; i < q; ++i) {
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		--u; --v;
		--l;
		int lca = get_lca(u, v);
		if (tin[v] > tin[u]) {
			swap(v, u);
		}

		if (v == lca) {
			int from = tin[v], to = tin[u] + 1;
			int res = find_odd(from, to, l, r);
			if (res == -1) {
				cout << "-1\n";
			} else {
				cout << res + 1 << "\n";
			}
		} else {
			int from = tout[v], to = tin[u] + 1;
			if (arr[lca] < l || r <= arr[lca]) {
				int res = find_odd(from, to, l, r);
				if (res == -1) {
					cout << "-1\n";
				} else {
					cout << res + 1 << "\n";
				}
			} else {
				int res = find_odd(from, to, l, arr[lca]);
				if (res != -1) {
					cout << res + 1 << "\n";
				} else {
					res = find_odd(from, to, arr[lca] + 1, r);
					if (res != -1) {
						cout << res + 1 << "\n";
					} else {
						res = find_odd(from, to, arr[lca], arr[lca] + 1);
						if (res == -1) {
							cout << arr[lca] + 1 << "\n";
						} else {
							cout << "-1\n";
						}
					}
				}
			}
		}
	}
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}