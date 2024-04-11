#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector<int> order;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		order.push_back(num);
	}

	if (order[0] != 0) {
		cout << "No\n";
		return;
	}

	vector<int> dist(n);
	vector<int> parent(n);
	function<void(int, int)> dfs = [&](int v, int p) {
		for (int to : graph[v]) {
			if (to != p) {
				parent[to] = v;
				dist[to] = dist[v] + 1;
				dfs(to, v);
			}
		}
	};

	dfs(order[0], -1);

	vector<int> where(n);
	for (int i = 0; i < n; ++i) {
		where[order[i]] = i;
	}

	for (int i = 1; i < n; ++i) {
		if (dist[order[i - 1]] > dist[order[i]] || where[parent[order[i - 1]]] > where[parent[order[i]]]) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}