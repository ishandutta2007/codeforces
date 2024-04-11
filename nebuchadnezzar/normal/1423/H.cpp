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

struct dsu_helper {
	vector<int>& dsu;
	vector<int>& dsu_sz;
	vector<pair<int*, int>>& dsu_mem;
	int dsu_mem_sz;
	dsu_helper(vector<int>& _dsu, vector<int>& _dsu_sz, vector<pair<int*, int>>& _dsu_mem) : dsu(_dsu), dsu_sz(_dsu_sz), dsu_mem(_dsu_mem), dsu_mem_sz(szof(dsu_mem)) {}

	int get_root(int v) {
		while (v != dsu[v]) {
			v = dsu[v];
		}
		return v;
	}

	void unite(int a, int b) {
		a = get_root(a);
		b = get_root(b);
		if (a == b) {
			return;
		}
		if (dsu_sz[a] < dsu_sz[b]) {
			swap(a, b);
		}
		dsu_mem.push_back({&dsu[b], dsu[b]});
		dsu[b] = a;
		dsu_mem.push_back({&dsu_sz[a], dsu_sz[a]});
		dsu_sz[a] += dsu_sz[b];
	}

	~dsu_helper() {
		while (szof(dsu_mem) != dsu_mem_sz) {
			*dsu_mem.back().ff = dsu_mem.back().ss;
			dsu_mem.pop_back();
		}
	}

	int get_sz(int v) {
		return dsu_sz[get_root(v)];
	}
};

void solve() {
	int n, q, k;
	cin >> n >> q >> k;
	vector<tuple<int, int, int>> inp;
	vector<int> first_in_day = {0};
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			inp.push_back({t, a, b});
		} else if (t == 2) {
			int a;
			cin >> a;
			--a;
			inp.push_back({t, a, -1});
		} else {
			inp.push_back({t, -1, -1});
			first_in_day.push_back(i + 1);
		}
	}

	first_in_day.push_back(q);

	int bpv = 1;
	while (bpv < q) {
		bpv *= 2;
	}

	vector<vector<pii>> add_here(bpv * 2);

	auto add_seg = [&](int l, int r, int a, int b) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				add_here[l++].push_back({a, b});
			}
			if (r & 1) {
				add_here[--r].push_back({a, b});
			}
			l /= 2; r /= 2;
		}
	};

	int day = 0;
	for (int i = 0; i < q; ++i) {
		while (day + 1 < szof(first_in_day) && first_in_day[day + 1] == i) {
			++day;
		}
		if (get<0>(inp[i]) == 1) {
			int l = i;
			int r = first_in_day[min(day + k, szof(first_in_day) - 1)];
			add_seg(l, r, get<1>(inp[i]), get<2>(inp[i]));
		}
	}

	vector<int> dsu(n);
	iota(dsu.begin(), dsu.end(), 0);
	vector<int> dsu_sz(n, 1);
	vector<pair<int*, int>> dsu_mem;
	vector<int> ans;

	function<void(int, int, int)> dfs = [&](int v, int vl, int vr) {
		dsu_helper helper(dsu, dsu_sz, dsu_mem);
		for (auto e : add_here[v]) {
			helper.unite(e.ff, e.ss);
		}

		if (vl + 1 == vr) {
			if (vl < q && get<0>(inp[vl]) == 2) {
				ans.push_back(helper.get_sz(get<1>(inp[vl])));
			}
			return;
		}

		int vm = (vl + vr) / 2;
		dfs(v * 2, vl, vm);
		dfs(v * 2 + 1, vm, vr);
	};

	dfs(1, 0, bpv);

	for (int num : ans) {
		cout << num << "\n";
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