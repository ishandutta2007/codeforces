#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	ll s;
	cin >> n >> s;
	if (s < n * 2 - 1 || s > (ll) n * (n + 1) / 2) {
		cout << "No\n";
		return;
	}
	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		ll cur = 1;
		vector<int> arrp(n);
		vector<int> depth(n);
		depth[0] = 1;
		int c = 0;
		for (int i = 1; i < n; ++i) {
			while (arrp[c] == mid) {
				++c;
			}
			arrp[c]++;
			depth[i] = depth[c] + 1;
			cur += depth[i];
		}

		if (cur <= s) {
			r = mid;
		} else {
			l = mid;
		}
	}

	vector<set<int>> graph(n);
	vector<int> depth(n);
	vector<int> parent(n);
	depth[0] = 1;
	ll sum = 1;
	int c = 0;
	for (int i = 1; i < n; ++i) {
		while (szof(graph[c]) == r) {
			++c;
		}
		graph[c].insert(i);
		depth[i] = depth[c] + 1;
		parent[i] = c;
		sum += depth[i];
	}

	set<pii> leaves;
	for (int i = 1; i < n; ++i) {
		if (szof(graph[i]) == 0) {
			leaves.insert({depth[i], i});
		}
	}

	while (sum < s) {
		int v = leaves.begin()->ss;
		leaves.erase(leaves.begin());
		int u = (--leaves.end())->ss;
		if (sum - depth[v] + depth[u] + 1 > s) {
			bool found = false;
			for (int i = 0; i < n; ++i) {
				if (i == v) {
					continue;
				}
				if (sum - depth[v] + depth[i] + 1 == s && szof(graph[i]) < r) {
					found = true;
					graph[parent[v]].erase(v);
					graph[i].insert(v);
					sum = sum - depth[v] + depth[i] + 1;
					depth[v] = depth[i] + 1;
					parent[v] = i;
					break;
				}
			}
			if (!found) {
				int best = -1;
				int mem = -1;
				for (int i = 0; i < n; ++i) {
					if (i == v) {
						continue;
					}
					if (sum - depth[v] + depth[i] + 1 <= s && szof(graph[i]) < r) {
						found = true;
						if (best < depth[i]) {
							best = depth[i];
							mem = i;
						}
					}
				}
				if (mem != -1) {
					graph[parent[v]].erase(v);
					if (!szof(graph[parent[v]])) {
						leaves.insert({depth[parent[v]], parent[v]});
					}
					leaves.erase({depth[mem], mem});
					graph[mem].insert(v);
					sum = sum - depth[v] + depth[mem] + 1;
					depth[v] = depth[mem] + 1;
					parent[v] = mem;
					leaves.insert({depth[v], v});
				} else {
					leaves.insert({depth[v], v});
					for (int i = 0; i < 3; ++i) {
						while (true) {
							int a = rnd(0, szof(leaves));
							auto it = leaves.begin();
							for (int q = 0; q < a; ++q) {
								++it;
							}
							v = it->ss;
							u = rnd(0, n - 1);
							if (u >= v) {
								++u;
							}
							if (sum - depth[v] + depth[u] + 1 > s) {
								continue;
							}
							leaves.erase({depth[v], v});
							leaves.erase({depth[u], u});
							graph[parent[v]].erase(v);
							if (!szof(graph[parent[v]])) {
								leaves.insert({depth[parent[v]], parent[v]});
							}
							graph[u].insert(v);
							sum = sum - depth[v] + depth[u] + 1;
							depth[v] = depth[u] + 1;
							parent[v] = u;
							leaves.insert({depth[v], v});
						}
					}
				}
			} else {
				break;
			}
		} else {
			leaves.erase(--leaves.end());
			graph[parent[v]].erase(v);
			if (!szof(graph[parent[v]])) {
				leaves.insert({depth[parent[v]], parent[v]});
			}
			graph[u].insert(v);
			sum = sum - depth[v] + depth[u] + 1;
			depth[v] = depth[u] + 1;
			parent[v] = u;
			leaves.insert({depth[v], v});
		}

		// cerr << sum << endl;
		// for (int i = 0; i < n; ++i) {
		// 	for (int to : graph[i]) {
		// 		cerr << i << " " << to << endl;
		// 	}
		// }
		// cerr << endl;
	}


	// int maxv = 0;
	// for (int i = 0; i < n; ++i) {
	// 	maxv = max(maxv, szof(graph[i]));
	// 	for (int to : graph[i]) {
	// 		cerr << i << " " << to << endl;
	// 	}
	// }

	// assert(maxv == r);

	cout << "Yes\n";
	for (int i = 1; i < n; ++i) {
		cout << parent[i] + 1 << " ";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}