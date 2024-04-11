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


void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> state;
	for (char c : s) {
		state.push_back(c - '0');
	}
	vector<vector<int>> here(n);
	vector<vector<int>> sets;
	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		sets.push_back({});
		for (int j = 0; j < c; ++j) {
			int ind;
			cin >> ind;
			--ind;
			here[ind].push_back(i);
			sets[i].push_back(ind);
		}
	}
	// vector<pii> edges(n, {-1, -1});
	// queue<int> qu;
	// for (int i = 0; i < n; ++i) {
	// 	if (szof(here[i]) == 1) {
	// 		qu.push(i);
	// 	}
	// }

	// while (szof(qu)) {
	// 	int pos = qu.front();
	// 	qu.pop();

	// 	// cerr << pos << endl;

	// 	if (szof(here[pos]) == 0) {
	// 		continue;
	// 	}

	// 	int flip = 0;
	// 	if (state[pos] == 0) {
	// 		flip = 1;
	// 	}

	// 	int ind = here[pos][0];
	// 	for (int other : sets[ind]) {
	// 		state[other] ^= flip;
	// 		here[other].erase(find(here[other].begin(), here[other].end(), ind));
	// 		if (szof(here[other]) == 1) {
	// 			qu.push(other);
	// 		}
	// 	}
	// }

	vector<int> dsu(k + 1);
	iota(dsu.begin(), dsu.end(), 0);
	vector<pii> szs(k + 1, {0, 1});
	vector<int> fl(k + 1);
	int ans = 0;

	auto get_root = [&](int v) {
		int mem = v;
		int cfl = 0;
		while (dsu[v] != v) {
			cfl ^= fl[v];
			v = dsu[v];
		}
		int ret_fl = cfl;
		while (mem != v) {
			int tmp = dsu[mem];
			int tmp_fl = fl[mem];
			fl[mem] = cfl;
			dsu[mem] = v;
			cfl ^= tmp_fl;
			mem = tmp;
		}
		return pii(v, ret_fl);
	};

	auto add_edge = [&](int a, int b, int x) {
		// cerr << a << " " << b << " " << x << endl;
		auto [ra, fa] = get_root(a);
		auto [rb, fb] = get_root(b);

		if (rb == k) {
			swap(ra, rb);
			swap(fa, fb);
		}

		if (ra == rb) {
			return;
		}

		if (ra == k) {
			ans -= szs[ra].ff;
		} else {
			ans -= min(szs[ra].ff, szs[ra].ss);
		}
		ans -= min(szs[rb].ff, szs[rb].ss);

		dsu[rb] = ra;
		x ^= fa ^ fb;
		fl[rb] = x;
		if (x == 0) {
			szs[ra].ff += szs[rb].ff;
			szs[ra].ss += szs[rb].ss;
		} else {
			szs[ra].ff += szs[rb].ss;
			szs[ra].ss += szs[rb].ff;
		}

		if (ra == k) {
			ans += szs[ra].ff;
		} else {
			ans += min(szs[ra].ff, szs[ra].ss);
		}
		// cerr << szs[ra].ff << " " << szs[rb].ss << endl;
	};

	for (int i = 0; i < n; ++i) {
		if (szof(here[i]) == 2) {
			add_edge(here[i][0], here[i][1], 1 - state[i]);
		} else if (szof(here[i]) == 1) {
			if (state[i] == 0) {
				add_edge(here[i][0], k, 1);
			} else {
				add_edge(here[i][0], k, 0);
			}
		}
		cout << ans << "\n";
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