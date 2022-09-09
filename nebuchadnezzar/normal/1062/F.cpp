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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		sort(graph[i].begin(), graph[i].end());
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}
	vector<bool> used(n);
	vector<int> order;
	function<void(int)> dfs = [&](int v) {
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				dfs(to);
			}
		}
		order.push_back(v);
	};

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	vector<vector<int>> rgraph(n);
	for (int i = 0; i < n; ++i) {
		for (int to : graph[i]) {
			rgraph[to].push_back(i);
		}
	}

	reverse(order.begin(), order.end());
	vector<int> anscnt(n);

	for (int q = 0; q < 2; ++q) {
		// cerr << "q: " << q << endl;
		vector<int> out(n);
		vector<int> out2(n);
		int cnt = 0, cnt2 = 0;
		ll sum_bad = 0;
		set<int> bads;

		// for (int v : order) {
		// 	cerr << v + 1 << " ";
		// }
		// cerr << endl;

		for (int v : order) {
			cnt += 1;
			++cnt2;
			sum_bad += v;
			for (int from : rgraph[v]) {
				out[from]++;
				if (out[from] == 1) {
					--cnt;
					sum_bad -= from;
					for (int from2 : rgraph[from]) {
						out2[from2]++;
						if (out2[from2] == 1) {
							--cnt2;
						}
					}
				}
			}
			// cerr << v + 1 << " " << cnt << endl;
			if (cnt == 1) {
				anscnt[v] += 0;
				// cerr << "+= 0" << endl;
			} else if (cnt == 2) {
				// int other = sum_bad - v;
				int cnt3 = cnt2;
				for (int from : rgraph[v]) {
					if (out2[from] == 0) {
						--cnt3;
					}
				}
				assert(cnt3 >= 2);
				if (cnt3 == 2) {
					anscnt[v] += 1;
					// cerr << "+= 1" << endl;
				} else {
					anscnt[v] += 123;
					// cerr << "+= inf" << endl;
				}
			} else {
				anscnt[v] += 123;
				// cerr << "+= inf" << endl;
			}
		}

		reverse(order.begin(), order.end());
		swap(graph, rgraph);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (anscnt[i] <= 1) {
			++ans;
		}
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