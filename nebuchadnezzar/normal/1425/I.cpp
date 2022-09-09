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
typedef unsigned int uint;

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

struct my_bitset {
	int sz;
	vector<uint> arr;
	my_bitset(int _sz) : sz(_sz), arr((sz + 31) / 32) {}

	void set_all() {
		for (int i = 0; (i + 1) * 32 <= sz; ++i) {
			arr[i] = -1;
		}
		if (sz % 32) {
			arr.back() = (1 << (sz % 32)) - 1;
		}
	}
};

int cut_copy(my_bitset& a, int l, int r, my_bitset& b) {
	int ret = 0;
	int lg = (l + 31) / 32;
	int rg = r / 32;
	for (int i = lg; i < rg; ++i) {
		ret += __builtin_popcount(a.arr[i]);
		b.arr[i] |= a.arr[i];
		a.arr[i] = 0;
	}
	if (lg > rg) {
		uint val = ((a.arr[lg - 1] >> (l % 32)) << (l % 32)) & ((1 << (r % 32)) - 1);
		ret += __builtin_popcount(val);
		b.arr[lg - 1] |= val;
		a.arr[lg - 1] ^= val;
	} else {
		if (l % 32) {
			uint val = (a.arr[lg - 1] >> (l % 32)) << (l % 32);
			ret += __builtin_popcount(val);
			b.arr[lg - 1] |= val;
			a.arr[lg - 1] ^= val;
		}
		if (r % 32) {
			uint val = a.arr[rg] & ((1 << (r % 32)) - 1);
			ret += __builtin_popcount(val);
			b.arr[rg] |= val;
			a.arr[rg] ^= val;
		}
	}

	return ret;
}

const int MAXD = 11;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> arra(n);
	for (int& num : arra) {
		cin >> num;
	}

	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}

	vector<int> depth(n);
	vector<vector<pii>> lr(n, vector<pii>(MAXD, {INF, -INF}));
	vector<vector<int>> on_layer(MAXD);

	function<void(int, int)> dfs = [&](int v, int d) {
		depth[v] = d;
		for (int i = d; i < MAXD; ++i) {
			lr[v][i].ff = szof(on_layer[i]);
		}
		on_layer[d].push_back(v);
		for (int to : graph[v]) {
			dfs(to, d + 1);
		}
		for (int i = d; i < MAXD; ++i) {
			lr[v][i].ss = szof(on_layer[i]);
		}
	};

	dfs(0, 0);

	vector<int> reqs;
	for (int i = 0; i < q; ++i) {
		int v;
		cin >> v;
		--v;
		reqs.push_back(v);
	}

	const int SMALL_A = 100000;

	map<int, vector<int>> by_a;
	vector<int> big_a_inds;

	for (int i = 0; i < n; ++i) {
		if (arra[i] <= SMALL_A) {
			by_a[arra[i]].push_back(i);
		} else {
			big_a_inds.push_back(i);
		}
	}

	vector<pii> ans(q);

	for (auto& p : by_a) {
		int cur_a = p.ff;
		set<int> cur_inds(p.ss.begin(), p.ss.end());
		for (int i = 0; i < MAXD; ++i) {
			vector<int> left_on_layer;
			for (int j = 0; j < szof(on_layer[i]); ++j) {
				if (cur_inds.count(on_layer[i][j])) {
					left_on_layer.push_back(j);
				}
			}
			if (!szof(left_on_layer)) {
				continue;
			}
			vector<my_bitset> mem(cur_a + 1, my_bitset(szof(left_on_layer)));
			int mem_ind = 0;
			mem[0].set_all();
			for (int j = 0; j < q; ++j) {
				if (depth[reqs[j]] > i) {
					int next = (mem_ind + 1) % (cur_a + 1);
					cut_copy(mem[mem_ind], 0, szof(left_on_layer), mem[next]);
					mem_ind = next;
					continue;
				}
				auto [l, r] = lr[reqs[j]][i];
				// cerr << cur_a << " " << i << " " << j << " " << l << " " << r << endl;
				l = lower_bound(left_on_layer.begin(), left_on_layer.end(), l) - left_on_layer.begin();
				r = lower_bound(left_on_layer.begin(), left_on_layer.end(), r) - left_on_layer.begin();
				if (l < r) {
					int to = (mem_ind + cur_a) % (cur_a + 1);
					int val = cut_copy(mem[mem_ind], l, r, mem[to]);
					// cerr << cur_a << " " << i << " " << j << " " << val << endl;
					ans[j].ss += val;
					ans[j].ff += (i - depth[reqs[j]]) * val;
				}

				int next = (mem_ind + 1) % (cur_a + 1);
				cut_copy(mem[mem_ind], 0, szof(left_on_layer), mem[next]);
				mem_ind = next;
			}
		}
	}

	{
		set<int> cur_inds(big_a_inds.begin(), big_a_inds.end());
		for (int i = 0; i < MAXD; ++i) {
			vector<int> left_on_layer;
			for (int j = 0; j < szof(on_layer[i]); ++j) {
				if (cur_inds.count(on_layer[i][j])) {
					left_on_layer.push_back(j);
				}
			}
			if (!szof(left_on_layer)) {
				continue;
			}
			vector<vector<int>> will_become_alive(q);
			set<int> alive;
			for (int j = 0; j < szof(left_on_layer); ++j) {
				alive.insert(j);
			}
			
			for (int j = 0; j < q; ++j) {
				for (int ind : will_become_alive[j]) {
					alive.insert(ind);
				}
				if (depth[reqs[j]] > i) {
					continue;
				}
				auto [l, r] = lr[reqs[j]][i];
				l = lower_bound(left_on_layer.begin(), left_on_layer.end(), l) - left_on_layer.begin();
				r = lower_bound(left_on_layer.begin(), left_on_layer.end(), r) - left_on_layer.begin();
				if (l < r) {
					auto it = alive.lower_bound(l);
					int cnt = 0;
					while (it != alive.end() && *it < r) {
						int ind = *it;
						auto old_it = it;
						++it;
						int v = on_layer[i][left_on_layer[ind]];
						if (j + arra[v] < q) {
							will_become_alive[j + arra[v]].push_back(ind);
						}
						alive.erase(old_it);
						++cnt;
					}
					ans[j].ss += cnt;
					ans[j].ff += (i - depth[reqs[j]]) * cnt;
				}
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i].ff << " " << ans[i].ss << endl;
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