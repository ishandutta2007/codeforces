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
uniform_real_distribution<double> d_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }
double rnd() {
	return d_distr(tw);
}

struct node {
	double y;
	int l, r;
	int x, val, sum, best;
	node() : y(rnd()), l(0), r(0), x(0), val(0), sum(0), best(0) {}
	node(int _x, int _val) : y(rnd()), l(0), r(0), x(_x), val(_val), sum(_val), best(_val) {}
};

vector<node> treap;

void t_upd(int v) {
	int vl = treap[v].l;
	int vr = treap[v].r;
	treap[v].sum = treap[vl].sum + treap[v].val + treap[vr].sum;
	treap[v].best = max(max(treap[vl].best, treap[vr].best), treap[v].val);
}

void t_lower_bound(int v, int& vl, int& vr, int val) {
	if (v == 0) {
		vl = vr = 0;
		return;
	}
	if (treap[v].x < val) {
		t_lower_bound(treap[v].r, treap[v].r, vr, val);
		vl = v;
		t_upd(vl);
	} else {
		t_lower_bound(treap[v].l, vl, treap[v].l, val);
		vr = v;
		t_upd(vr);
	}
}

void t_merge(int vl, int vr, int& v) {
	if (vl == 0) {
		v = vr;
		return;
	}
	if (vr == 0) {
		v = vl;
		return;
	}
	if (treap[vl].y > treap[vr].y) {
		t_merge(treap[vl].r, vr, treap[vl].r);
		v = vl;
		t_upd(v);
	} else {
		t_merge(vl, treap[vr].l, treap[vr].l);
		v = vr;
		t_upd(v);
	}
}

int get_right(int v) {
	while (treap[v].r != 0) {
		v = treap[v].r;
	}
	return v;
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> arr;
	map<int, set<int>> where;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		where[num].insert(i);
	}

	map<int, int> last_change;

	vector<pair<pii, pair<pii, int>>> edges;

	for (int i = 0; i < q; ++i) {
		int pos, val;
		cin >> pos >> val;
		--pos;
		int old_val = arr[pos];
		if (old_val == val) {
			continue;
		}
		edges.push_back({{last_change[old_val], i + 1}, {{*where[old_val].begin(), *--where[old_val].end()}, szof(where[old_val])}});
		if (szof(where[val])) {
			edges.push_back({{last_change[val], i + 1}, {{*where[val].begin(), *--where[val].end()}, szof(where[val])}});
		}
		last_change[old_val] = i + 1;
		last_change[val] = i + 1;
		where[old_val].erase(pos);
		where[val].insert(pos);
		arr[pos] = val;
	}

	for (auto& p : where) {
		if (szof(p.ss)) {
			edges.push_back({{last_change[p.ff], q + 1}, {{*p.ss.begin(), *--p.ss.end()}, szof(p.ss)}});
		}
	}

	int bpv = 1;
	while (bpv < q + 1) {
		bpv *= 2;
	}

	vector<vector<pair<pii, int>>> here(bpv * 2);
	for (auto e : edges) {
		int l = e.ff.ff + bpv;
		int r = e.ff.ss + bpv;
		while (l < r) {
			if (l & 1) {
				here[l++].push_back(e.ss);
			}
			if (r & 1) {
				here[--r].push_back(e.ss);
			}
			l /= 2;
			r /= 2;
		}
	}

	vector<int> ans(q + 1);

	treap.push_back(node());

	int root = 0;
	for (int i = 0; i <= n; ++i) {
		treap.push_back(node(i, 0));
		t_merge(root, szof(treap) - 1, root);
	}

	// unordered_set<int> free_spaces;

	vector<int> order;
	function<void(int, int, int)> dfs = [&](int v, int l, int r) {
		// cerr << "dfs " << v << " " << l << " " << r << endl;
		if (l >= q + 1) {
			return;
		}
		// vector<pair<int, pii>> changes;
		vector<tuple<int, int, int>> changes;
		// int mem_sum = sum;
		for (auto e : here[v]) {
			int val = e.ss;
			int lg = e.ff.ff;
			int rg = e.ff.ss;
			int vl, vm, vr;
			t_lower_bound(root, vl, vr, rg + 1);
			t_lower_bound(vl, vl, vm, lg + 1);
			int nv = get_right(vl);
			lg = treap[nv].x;
			changes.push_back({lg, vm, treap[nv].val});
			val = max(val, max(treap[vm].best, treap[nv].val));

			order.clear();
			int cur = vl;
			while (treap[cur].r) {
				order.push_back(cur);
				cur = treap[cur].r;
			}
			order.push_back(cur);
			treap[nv].val = val;
			reverse(order.begin(), order.end());
			for (int u : order) {
				t_upd(u);
			}

			t_merge(vl, vr, root);
		}

		if (l + 1 == r) {
			ans[l] = treap[root].sum;
		} else {
			int m = (l + r) / 2;
			dfs(v * 2, l, m);
			dfs(v * 2 + 1, m, r);
		}

		while (szof(changes)) {
			int vl, vr;
			auto [lg, vm, val] = changes.back();
			t_lower_bound(root, vl, vr, lg + 1);
			
			order.clear();
			int cur = vl;
			while (treap[cur].r) {
				order.push_back(cur);
				cur = treap[cur].r;
			}
			order.push_back(cur);
			treap[cur].val = val;
			reverse(order.begin(), order.end());
			for (int u : order) {
				t_upd(u);
			}

			t_merge(vl, vm, vl);
			t_merge(vl, vr, root);
			changes.pop_back();
		}
	};

	dfs(1, 0, bpv);

	for (int i = 0; i <= q; ++i) {
		cout << n - ans[i] << "\n";
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