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
	map<int, int> cnt;
	cnt[0]++;
	int bal = 0;
	vector<int> tmp = {0};
	for (char c : s) {
		if (c == '0') {
			++bal;
		} else {
			--bal;
		}
		cnt[bal]++;
		tmp.push_back(bal);
	}

	int minbal = cnt.begin()->ff;
	vector<int> edges(szof(cnt) - 1);
	for (int i = 0; i < szof(s); ++i) {
		int a = tmp[i];
		int b = tmp[i + 1];
		edges[min(a, b) - minbal]++;
	}

	set<int> odd_nodes;
	for (int i = 0; i < szof(cnt); ++i) {
		int val = 0;
		if (i) {
			val += edges[i - 1];
		}
		if (i < szof(cnt) - 1) {
			val += edges[i];
		}
		if (val % 2) {
			odd_nodes.insert(i);
		}
	}
	set<int> have_edges;
	for (int i = 0; i < szof(cnt) - 1; ++i) {
		have_edges.insert(i);
	}

	auto change_edge = [&](int e, int val) {
		edges[e] += val;
		if (edges[e] == 0) {
			have_edges.erase(e);
		} else {
			have_edges.insert(e);
		}
		{
			int val = edges[e];
			if (e > 0) {
				val += edges[e - 1];
			}
			if (val % 2) {
				odd_nodes.insert(e);
			} else {
				odd_nodes.erase(e);
			}
		}
		{
			int val = edges[e];
			if (e < szof(cnt) - 2) {
				val += edges[e + 1];
			}
			if (val % 2) {
				odd_nodes.insert(e + 1);
			} else {
				odd_nodes.erase(e + 1);
			}
		}
	};

	auto check = [&](int st) {
		if (!szof(have_edges)) {
			return true;
		}
		if (szof(have_edges) != *--have_edges.end() - *have_edges.begin() + 1) {
			return false;
		}
		if (szof(odd_nodes) > 2) {
			return false;
		}
		if (szof(odd_nodes) == 2 && !odd_nodes.count(st)) {
			return false;
		}
		if (st < *have_edges.begin() || st > *--have_edges.end() + 1) {
			return false;
		}
		return true;
	};

	int pos = 0;
	vector<int> seq;
	for (int i = 0; i < szof(s); ++i) {
		seq.push_back(pos);
		// cerr << pos << endl;
		// try to go to (pos + 1)
		if (pos < minbal + szof(cnt) - 1 && edges[pos - minbal]) {
			change_edge(pos - minbal, -1);
			if (check(pos + 1 - minbal)) {
				++pos;
				continue;
			} else {
				change_edge(pos - minbal, 1);
			}
		}

		assert(pos > minbal && edges[pos - minbal - 1]);
		change_edge(pos - minbal - 1, -1);
		assert(check(pos - 1 - minbal));
		--pos;
	}

	seq.push_back(pos);

	for (int i = 0; i < szof(s); ++i) {
		if (seq[i + 1] > seq[i]) {
			cout << "0";
		} else {
			cout << "1";
		}
	}
	cout << "\n";
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