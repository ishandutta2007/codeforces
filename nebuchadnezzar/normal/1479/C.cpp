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
	int l, r;
	cin >> l >> r;
	++r;
	vector<pair<pii, int>> edges;
	if (l == 1) {
		edges.push_back({{0, 31}, 1});
		++l;
	}
	if (l < r) {
		--l; --r;
		vector<pii> segs;
		int tmp = r;
		for (int i = 19; i >= 0; --i) {
			if (tmp - (1 << i) >= l) {
				// cerr << tmp << " " << tmp + (1 << i) << endl;
				tmp -= (1 << i);
				segs.push_back({i, tmp});
			}
		}
		reverse(segs.begin(), segs.end());
		int val = 1;
		int cnt = 0;
		if (segs[0].ff == 0) {
			val = segs[0].ss;
			++cnt;
			edges.push_back({{1, 31}, 1});
		}
		vector<int> nodes = {0, val};
		edges.push_back({{0, 1}, val});
		for (int i = 1; i < 21; ++i) {
			if (cnt == szof(segs)) {
				break;
			}
			if (segs[cnt].ff == i) {
				edges.push_back({{szof(nodes), 31}, 1});
				val = segs[cnt].ss;
				++cnt;
			}
			int tmpsz = szof(edges);
			for (int j = 0; j < tmpsz; ++j) {
				if (edges[j].ff.ss == szof(nodes) - 1) {
					auto e = edges[j];
					e.ss += val - nodes.back();
					e.ff.ss = szof(nodes);
					edges.push_back(e);
				}
			}

			edges.push_back({{szof(nodes) - 1, szof(nodes)}, val + (1 << (i - 1)) - nodes.back()});

			nodes.push_back(val);
		}
	}

	cout << "YES\n";
	cout << "32 " << szof(edges) << "\n";
	for (auto e : edges) {
		cout << e.ff.ff + 1 << " " << e.ff.ss + 1 << " " << e.ss << "\n";
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