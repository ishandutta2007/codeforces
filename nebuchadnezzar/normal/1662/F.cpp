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

pair<pii, pii> comb(pair<pii, pii> a, pair<pii, pii> b) {
	return {max(a.ff, b.ff), min(a.ss, b.ss)};
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	--a; --b;
	vector<int> powers;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		powers.push_back(num);
	}
	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<pair<pii, pii>> segtree(bpv * 2, {{-INF, -1}, {INF, -1}});
	auto segtree_set = [&](int pos, pair<pii, pii> val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = comb(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		l += bpv; r += bpv;
		pair<pii, pii> ret = {{-INF, -1}, {INF, -1}};
		while (l < r) {
			if (l & 1) {
				ret = comb(ret, segtree[l++]);
			}
			if (r & 1) {
				ret = comb(ret, segtree[--r]);
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	for (int i = 0; i < n; ++i) {
		segtree_set(i, {{i + powers[i], i}, {i - powers[i], i}});
	}

	queue<pii> qu;
	qu.push({a, 0});
	segtree_set(a, {{-INF, a}, {INF, a}});
	while (szof(qu)) {
		auto [v, d] = qu.front();
		qu.pop();
		// cerr << v << " " << d << endl;
		if (v == b) {
			cout << d << "\n";
			break;
		}

		while (true) {
			auto tmp = segtree_get(max(0, v - powers[v]), v);
			if (tmp.ff.ff < v) {
				break;
			}
			int to = tmp.ff.ss;
			qu.push({to, d + 1});
			segtree_set(to, {{-INF, to}, {INF, to}});
		}

		while (true) {
			auto tmp = segtree_get(v, min(n, v + powers[v] + 1));
			if (tmp.ss.ff > v) {
				break;
			}
			int to = tmp.ss.ss;
			qu.push({to, d + 1});
			segtree_set(to, {{-INF, to}, {INF, to}});
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}