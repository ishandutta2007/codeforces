// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

bool check(vector<int> const& arr, vector<int> const& res) {
	map<int, int> node_by_val;
	int n = 0;
	for (int num : arr) {
		if (!node_by_val.count(num)) {
			node_by_val[num] = n++;
		}
	}
	vector<vector<int>> graph(n);
	// cerr << "edges" << endl;
	for (int i = 0; i < szof(arr); ++i) {
		int a = node_by_val[arr[i]];
		int b = node_by_val[res[i]];
		// cerr << a << " " << b << endl;
		graph[a].push_back(b);
	}
	// cerr << "---" << endl;
	int mem = 0;
	for (int i = 0; i < n; ++i) {
		if (szof(graph[i]) > szof(graph[mem])) {
			mem = i;
		}
	}

	vector<int> cycle;
	function<void(int)> dfs = [&](int v) {
		while (szof(graph[v])) {
			int to = graph[v].back();
			graph[v].pop_back();
			dfs(to);
		}
		cycle.push_back(v);
	};

	dfs(0);
	cycle.pop_back();
	if (szof(cycle) != szof(arr)) {
		return false;
	}

	vector<vector<int>> graph2(n);
	vector<int> positions;
	for (int i = 0; i < szof(cycle); ++i) {
		if (cycle[i] == mem) {
			positions.push_back(i);
		}
	}

	for (int i = 0; i < szof(positions); ++i) {
		int nxt = (i + 1) % szof(positions);
		vector<int> seq;
		for (int p = (positions[i] + 1) % szof(arr); p != positions[nxt]; p = (p + 1) % szof(arr)) {
			seq.push_back(cycle[p]);
		}
		for (int j = 0; j < szof(seq) - 1; ++j) {
			graph2[seq[j]].push_back(seq[j + 1]);
		}
	}

	vector<int> used(n);
	function<bool(int)> dfs2 = [&](int v) {
		used[v] = 1;
		for (int to : graph2[v]) {
			if (!used[to]) {
				if (dfs2(to)) {
					return true;
				}
			} else if (used[to] == 1) {
				return true;
			}
		}
		used[v] = 2;
		return false;
	};

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			if (dfs2(i)) {
				return false;
			}
		}
	}

	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	// map<int, vector<int>> by_val;
	// for (int i = 0; i < n; ++i) {
	// 	int num;
	// 	cin >> num;
	// 	by_val[num].push_back(i);
	// 	arr.push_back(num);
	// }
	// int tmp = 0;
	// vector<int> cycle;
	// set<pii> have;
	// for (auto& v : by_val) {
	// 	have.insert({szof(v.ss), v.ff});
	// 	tmp += szof(v.ss) - 1;
	// }

	// while (szof(have)) {
	// 	auto it = --have.end();
	// 	if (szof(have) > 1 && szof(cycle)) {
	// 		auto it2 = it;
	// 		--it2;
	// 		if (arr[cycle.back()] == it->ss || (szof(cycle) == n - 2 && arr[cycle.back()] != it2->ss && arr[cycle.front()] == it2->ss)) {
	// 			it = it2;
	// 		}
	// 	}
	// 	int val = it->ss;
	// 	have.erase(it);
	// 	cycle.push_back(by_val[val].back());
	// 	by_val[val].pop_back();
	// 	if (szof(by_val[val])) {
	// 		have.insert({szof(by_val[val]), val});
	// 	}
	// }

	// vector<int> ans(n);
	// for (int i = 0; i < n; ++i) {
	// 	int next = (i + 1) % n;
	// 	ans[cycle[i]] = arr[cycle[next]];
	// }


	vector<int> res;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		res.push_back(num);
	}

	// cerr << cnt_cycles(arr, ans) << " " << 1 + tmp << endl;

	// assert(check(arr, ans));

	if (check(arr, res)) {
		cout << "AC\n";
	} else {
		cout << "WA\n";
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