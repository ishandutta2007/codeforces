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
typedef pair<ll, ll> pll;

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

bool is_prime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

vector<int> get_lca(vector<int> a, vector<int> const& b) {
	for (int i = 0; i < szof(a); ++i) {
		if (a[i] != b[i]) {
			a[i] = min(a[i], b[i]);
			fill(a.begin() + i + 1, a.end(), 0);
			break;
		}
	}
	return a;
}

bool is_parent(vector<int> const& a, vector<int> const& b) {
	for (int i = 0; i < szof(a); ++i) {
		if (a[i] != b[i]) {
			bool ret = a[i] < b[i];
			for (int j = i + 1; j < szof(a); ++j) {
				ret &= a[j] == 0;
				if (!ret) {
					break;
				}
			}
			return ret;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		++cnt[num];
	}

	vector<int> primes;

	for (int i = 2; i < 5005; ++i) {
		if (is_prime(i)) {
			primes.push_back(i);
		}
	}

	vector<pair<vector<int>, int>> nodes;

	for (auto num : cnt) {
		vector<int> cur(szof(primes));
		for (int i = 0; i < szof(primes); ++i) {
			int tmp = num.ff;
			while (tmp) {
				cur[i] += tmp / primes[i];
				tmp /= primes[i];
			}
		}
		reverse(cur.begin(), cur.end());
		nodes.push_back({cur, num.ss});
	}

	sort(nodes.begin(), nodes.end());

	vector<pii> edges;
	vector<vector<int>> graph_nodes(1, vector<int>(szof(primes)));
	vector<int> graph_weight = {0};
	vector<int> st = {0};

	for (int i = 0; i < szof(nodes); ++i) {
		auto lca = get_lca(graph_nodes[st.back()], nodes[i].ff);
		int last = -1;
		while (!is_parent(graph_nodes[st.back()], nodes[i].ff)) {
			if (last != -1) {
				edges.push_back({last, st.back()});
			}
			last = st.back();
			// edges.push_back({st.back(), st[szof(st) - 2]});
			st.pop_back();
		}
		if (lca != graph_nodes[st.back()]) {
			int nv = szof(graph_nodes);
			graph_nodes.push_back(lca);
			st.push_back(nv);
			graph_weight.push_back(0);
		}
		if (last != -1) {
			edges.push_back({st.back(), last});
		}
		if (lca != nodes[i].ff) {
			int nv = szof(graph_nodes);
			graph_nodes.push_back(nodes[i].ff);
			st.push_back(nv);
			graph_weight.push_back(nodes[i].ss);
		} else {
			graph_weight[st.back()] += nodes[i].ss;
		}
	}

	for (int i = 0; i < szof(st) - 1; ++i) {
		edges.push_back({st[i], st[i + 1]});
	}

	vector<vector<pii>> graph(szof(graph_nodes));

	// for (int i = 0; i < szof(graph_nodes); ++i) {
	// 	cerr << i << ":" << endl;
	// 	for (int j = 0; j < 10; ++j) {
	// 		cerr << graph_nodes[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }

	for (auto e : edges) {
		int w = 0;
		for (int i = 0; i < szof(primes); ++i) {
			w += abs(graph_nodes[e.ff][i] - graph_nodes[e.ss][i]);
		}
		// cerr << e.ff << " " << e.ss << " " << w << endl;
		graph[e.ff].push_back({e.ss, w});
		graph[e.ss].push_back({e.ff, w});
	}

	ll ans = INFL;

	function<pll(int, int)> dfs = [&](int v, int p) {
		pll ret = {0, graph_weight[v]};
		for (auto to : graph[v]) {
			if (to.ff != p) {
				auto tmp = dfs(to.ff, v);
				ret.ff += tmp.ff + (ll) to.ss * tmp.ss;
				ret.ss += tmp.ss;
			}
		}
		return ret;
	};

	for (int i = 0; i < szof(graph_nodes); ++i) {
		ll cur = dfs(i, i).ff;
		ans = min(ans, cur);
	}

	cout << ans << "\n";
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