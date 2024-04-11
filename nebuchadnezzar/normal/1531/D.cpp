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

vector<string> colors = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

struct value {
	int locked;
	int col[2];
	value() {}
	value(string s) {
		if (s == "lock") {
			locked = 1;
			col[0] = col[1] = -1;
		} else if (s == "unlock") {
			locked = 0;
			col[0] = col[1] = -1;
		} else {
			locked = -1;
			col[0] = find(colors.begin(), colors.end(), s) - colors.begin();
			col[1] = -1;
		}
	}
};

value comb(value const& val1, value const& val2) {
	value ret;
	ret.locked = val1.locked;
	if (val2.locked != -1) {
		ret.locked = val2.locked;
	}
	ret.col[0] = val1.col[0];
	ret.col[1] = val1.col[1];
	if (val1.locked == -1) {
		if (val2.col[0] != -1) {
			ret.col[0] = val2.col[0];
		}
		if (val2.col[1] != -1) {
			ret.col[1] = val2.col[1];
		}
	} else if (val1.locked == 0) {
		if (val2.col[0] != -1) {
			ret.col[0] = val2.col[0];
			ret.col[1] = val2.col[0];
		}
	} else {
		if (val2.col[1] != -1) {
			ret.col[0] = val2.col[1];
			ret.col[1] = val2.col[1];
		}
	}

	return ret;
}


void solve() {
	int n;
	cin >> n;

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<value> segtree(bpv * 2);

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		segtree[bpv + i] = value(s);
	}
	for (int i = n; i < bpv; ++i) {
		segtree[bpv + i] = value("lock");
	}

	for (int i = bpv - 1; i; --i) {
		segtree[i] = comb(segtree[i * 2], segtree[i * 2 + 1]);
	}

	auto get_color = [&]() {
		int tmp = segtree[1].col[0];
		if (tmp == -1) {
			tmp = 4;
		}
		return tmp;
	};

	cout << colors[get_color()] << "\n";

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int pos;
		string s;
		cin >> pos >> s;
		--pos;
		pos += bpv;
		segtree[pos] = value(s);
		pos /= 2;
		while (pos) {
			segtree[pos] = comb(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}

		cout << colors[get_color()] << "\n";
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