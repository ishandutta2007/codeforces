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
	string s;
	cin >> s;
	string t = s;
	reverse(s.begin(), s.end());
	t += s;
	reverse(s.begin(), s.end());

	int eq = 0;
	{
		int l = 0, r = 0;
		vector<int> z(szof(t));
		for (int i = 1; i < szof(t); ++i) {
			if (i < r) {
				z[i] = min(r - i, z[i - l]);
			}
			while (i + z[i] < szof(t) && t[z[i]] == t[i + z[i]]) {
				++z[i];
			}
			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
			if (i == szof(s)) {
				eq = min(szof(s), z[i]);
			}
		}
	}

	string tmp;
	for (char c : s) {
		tmp += c;
		tmp += '!';
	}
	tmp.pop_back();

	vector<int> rad(szof(tmp));
	{
		int c = 0, r = 1;
		rad[0] = 1;
		for (int i = 1; i < szof(tmp); ++i) {
			if (i < c + r) {
				rad[i] = min(c + r - i, rad[2 * c - i]);
			}
			while (i - rad[i] >= 0 && i + rad[i] < szof(tmp) && tmp[i - rad[i]] == tmp[i + rad[i]]) {
				++rad[i];
			}
			if (i + rad[i] > c + r) {
				c = i;
				r = rad[i];
			}
		}
	}

	int ans = 0;
	int l = 0, r = 0;

	auto upd = [&](int cl, int cr) {
		if (cl + cr > szof(s)) {
			return;
		}
		if (cl + cr > ans) {
			ans = cl + cr;
			l = cl;
			r = cr;
		}
	};

	for (int i = 0; i < szof(tmp); ++i) {
		if (i % 2 == 0) {
			rad[i] = (rad[i] + 1) / 2 * 2 - 1;
			int from = i / 2 - rad[i] / 2;
			int to = i / 2 + rad[i] / 2 + 1;
			if (eq >= from) {
				upd(to, from);
			}
			if (szof(s) - eq <= to) {
				upd(szof(s) - to, szof(s) - from);
			}
		} else {
			rad[i] = rad[i] / 2 * 2;
			int from = i / 2 - rad[i] / 2 + 1;
			int to = i / 2 + rad[i] / 2 + 1;
			if (eq >= from) {
				upd(to, from);
			}
			if (szof(s) - eq <= to) {
				upd(szof(s) - to, szof(s) - from);
			}
		}
	}

	/*
	{
		string sans = s.substr(0, l) + s.substr(szof(s) - r, r);
		string tmp = sans;
		reverse(tmp.begin(), tmp.end());
		assert(tmp == sans);
	}

	int best = 0;
	for (int i = 0; i <= szof(s); ++i) {
		for (int j = 0; i + j <= szof(s); ++j) {
			auto cur = s.substr(0, i) + s.substr(szof(s) - j, j);
			auto tmp = cur;
			reverse(tmp.begin(), tmp.end());
			if (tmp == cur) {
				best = max(best, i + j);
			}
		}
	}

	assert(best == l + r);
	*/

	cout << s.substr(0, l) + s.substr(szof(s) - r, r) << "\n";
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