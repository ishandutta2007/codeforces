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
	int n, s;
	cin >> n >> s;
	--s;
	vector<vector<int>> graph(n * 3);
	for (int i = 0; i < n; ++i) {
		if (i < n - 1) {
			graph[i * 3].push_back((i + 1) * 3);
			graph[(i + 1) * 3 + 1].push_back(i * 3 + 1);
		}
		int num;
		cin >> num;
		if (num) {
			graph[i * 3].push_back(i * 3 + 2);
			graph[i * 3 + 2].push_back(i * 3);
		}
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (num) {
			graph[i * 3 + 1].push_back(i * 3 + 2);
			graph[i * 3 + 2].push_back(i * 3 + 1);
		}
	}

	queue<int> qu;
	vector<bool> used(szof(graph));
	qu.push(2);
	used[2] = true;
	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		for (int to : graph[v]) {
			if (!used[to]) {
				qu.push(to);
				used[to] = true;
			}
		}
	}

	if (used[s * 3 + 2]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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