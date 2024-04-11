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

const int MOD = 998'244'353;

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

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

vector<int> fact, inv_fact;

int cnk(int n, int k) {
	return mult(fact[n], mult(inv_fact[k], inv_fact[n - k]));
}

const int MAXN = 2e5 + 5;

struct node {
	int x, y;
	int add;
	int l, r;
	node() : x(0), y(0), add(0), l(0), r(0) {}
	node(int _x) : x(_x), y(rnd(0, INF)), add(0), l(0), r(0) {}
};

vector<node> treap;

void t_push(int v) {
	if (treap[v].add) {
		if (treap[v].l) {
			treap[treap[v].l].x += treap[v].add;
			treap[treap[v].l].add += treap[v].add;
		}
		if (treap[v].r) {
			treap[treap[v].r].x += treap[v].add;
			treap[treap[v].r].add += treap[v].add;
		}
		treap[v].add = 0;
	}
}

int t_merge(int vl, int vr) {
	if (vl == 0 || vr == 0) {
		return vl + vr;
	}

	if (treap[vl].y > treap[vr].y) {
		t_push(vl);
		treap[vl].r = t_merge(treap[vl].r, vr);
		// t_upd(vl);
		return vl;
	} else {
		t_push(vr);
		treap[vr].l = t_merge(vl, treap[vr].l);
		// t_upd(vr);
		return vr;
	}
}

pii t_split(int v, int x) {
	if (v == 0) {
		return {0, 0};
	}

	t_push(v);
	if (treap[v].x < x) {
		auto tmp = t_split(treap[v].r, x);
		treap[v].r = tmp.ff;
		// t_upd(v);
		return {v, tmp.ss};
	} else {
		auto tmp = t_split(treap[v].l, x);
		treap[v].l = tmp.ss;
		// t_upd(v);
		return {tmp.ff, v};
	}
}

void solve() {
	treap.clear();
	treap.push_back(node());
	int n, m;
	cin >> n >> m;
	int root = 0;
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		auto [vl, vr] = t_split(root, y - 1);
		int vm;
		tie(vm, vr) = t_split(vr, y);
		if (vm == 0) {
			++cnt;
			if (vr != 0) {
				treap[vr].add++;
				treap[vr].x++;
			}
			treap.push_back(node(y));
			vr = t_merge(szof(treap) - 1, vr);
			root = t_merge(vl, vr);
		} else {
			vr = t_merge(vm, vr);
			if (vr != 0) {
				treap[vr].add++;
				treap[vr].x++;
			}
			root = t_merge(vl, vr);
		}
	}

	int left = n - 1 - cnt;
	// cerr << left << " " << n - 1 << endl;
	cout << cnk(n + left, left) << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact = {1};
	for (int i = 1; i <= MAXN * 2; ++i) {
		fact.push_back(mult(fact.back(), i));
	}

	inv_fact = {inv(fact.back())};

	for (int i = MAXN * 2; i >= 1; --i) {
		inv_fact.push_back(mult(inv_fact.back(), i));
	}

	reverse(inv_fact.begin(), inv_fact.end());

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