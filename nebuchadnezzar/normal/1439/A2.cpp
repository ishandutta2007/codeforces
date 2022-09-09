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
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> field(n, vector<bool>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field[i][j] = s[j] - '0';
		}
	}

	vector<tuple<pii, pii, pii>> outp;

	auto add_outp = [&](tuple<pii, pii, pii> const& t) {
		outp.push_back(t);
		field[get<0>(t).ff][get<0>(t).ss] = field[get<0>(t).ff][get<0>(t).ss] ^ 1;
		field[get<1>(t).ff][get<1>(t).ss] = field[get<1>(t).ff][get<1>(t).ss] ^ 1;
		field[get<2>(t).ff][get<2>(t).ss] = field[get<2>(t).ff][get<2>(t).ss] ^ 1;
	};

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j]) {
				if (j < m - 1) {
					add_outp({{i, j}, {i, j + 1}, {i + 1, j}});
				} else {
					add_outp({{i, j}, {i + 1, j}, {i + 1, j - 1}});
				}
			}
		}
	}

	for (int j = 0; j < m - 2; ++j) {
		if (field[n - 2][j] == 1 && field[n - 1][j] == 1) {
			add_outp({{n - 2, j}, {n - 1, j}, {n - 2, j + 1}});
		} else if (field[n - 2][j] == 1 && field[n - 1][j] == 0) {
			add_outp({{n - 2, j}, {n - 2, j + 1}, {n - 1, j + 1}});
		} else if (field[n - 2][j] == 0 && field[n - 1][j] == 1) {
			add_outp({{n - 1, j}, {n - 1, j + 1}, {n - 2, j + 1}});
		}
	}

	vector<tuple<pii, pii, pii>> vars = {
		{{n - 2, m - 2}, {n - 2, m - 1}, {n - 1, m - 2}},
		{{n - 2, m - 2}, {n - 1, m - 2}, {n - 1, m - 1}},
		{{n - 2, m - 2}, {n - 2, m - 1}, {n - 1, m - 1}},
		{{n - 1, m - 1}, {n - 2, m - 1}, {n - 1, m - 2}}
	};

	for (int mask = 0; mask < 1 << 4; ++mask) {
		int mem = szof(outp);
		for (int i = 0; i < 4; ++i) {
			if (mask & (1 << i)) {
				add_outp(vars[i]);
			}
		}

		if (field[n - 2][m - 2] == 0 && field[n - 2][m - 1] == 0 && field[n - 1][m - 2] == 0 && field[n - 1][m - 1] == 0) {
			break;
		}

		for (int i = 0; i < 4; ++i) {
			if (mask & (1 << i)) {
				add_outp(vars[i]);
			}
		}

		outp.resize(mem);
	}

	cout << szof(outp) << "\n";
	for (auto& p : outp) {
		cout << get<0>(p).ff + 1 << " " << get<0>(p).ss + 1 << " " << get<1>(p).ff + 1 << " " << get<1>(p).ss + 1 << " " << get<2>(p).ff + 1 << " " << get<2>(p).ss + 1 << "\n";
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