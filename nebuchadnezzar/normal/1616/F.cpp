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

bool check_colors(int c1, int c2, int c3) {
	if (c1 != -1 && c2 != -1 && c3 != -1) {
		if (c1 == c2 && c2 == c3) {
			return true;
		}
		if (c1 != c2 && c2 != c3 && c3 != c1) {
			return true;
		}
		return false;
	}
	return true;
}

int get_color(int a, int b, int c) {
	int arr[3] = {a, b, c};
	sort(arr, arr + 3);
	if (arr[1] == arr[2]) {
		return arr[2];
	}
	return 1 + 2 + 3 - arr[1] - arr[2];
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(n, -1));
	vector<pair<pii, int>> edges;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		edges.push_back({{a, b}, c});
		graph[a][b] = graph[b][a] = i;
	}

	vector<tuple<int, int, int>> trs;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (graph[i][j] != -1 && graph[j][k] != -1 && graph[k][i] != -1) {
					trs.push_back({graph[i][j], graph[j][k], graph[k][i]});
					if (!check_colors(edges[graph[i][j]].ss, edges[graph[j][k]].ss, edges[graph[k][i]].ss)) {
						cout << "-1\n";
						return;
					}
				}
			}
		}
	}

	function<bool()> rec = [&]() {
		vector<int> ccnt(m);

		for (auto [a, b, c] : trs) {
			int cnt = (edges[a].ss != -1) + (edges[b].ss != -1) + (edges[c].ss != -1);
			if (cnt == 3) {
				if (!check_colors(edges[a].ss, edges[b].ss, edges[c].ss)) {
					return false;
				}
			}
		}

		for (auto [a, b, c] : trs) {
			int cnt = (edges[a].ss != -1) + (edges[b].ss != -1) + (edges[c].ss != -1);
			if (cnt == 2) {
				int who = edges[a].ss == -1 ? a : (edges[b].ss == -1 ? b : c);
				edges[who].ss = get_color(edges[a].ss, edges[b].ss, edges[c].ss);
				if (rec()) {
					return true;
				}
				edges[who].ss = -1;
				return false;
			}
			ccnt[a]++; ccnt[b]++; ccnt[c]++;
		}

		int mem = -1;
		for (int i = 0; i < m; ++i) {
			if (edges[i].ss == -1 && (mem == -1 || ccnt[i] > ccnt[mem])) {
				mem = i;
			}
		}

		if (mem == -1) {
			return true;
		}

		for (int c = 1; c <= 3; ++c) {
			edges[mem].ss = c;
			if (rec()) {
				return true;
			}
			edges[mem].ss = -1;
		}

		return false;
	};

	if (rec()) {
		for (auto e : edges) {
			cout << e.ss << " ";
		}
		cout << "\n";
	} else {
		cout << "-1\n";
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