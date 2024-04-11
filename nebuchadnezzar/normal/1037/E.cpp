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
	int n, m, k;
	cin >> n >> m >> k;
	vector<set<int>> graph(n);
	vector<pii> edges;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].insert(b);
		graph[b].insert(a);
		edges.push_back({a, b});
	}

	queue<int> q;
	vector<int> pows(n);
	vector<bool> used(n);
	for (int i = 0; i < n; ++i) {
		pows[i] = szof(graph[i]);
		if (pows[i] < k) {
			q.push(i);
			used[i] = true;
		}
	}

	int left = n;
	while (szof(q)) {
		int v = q.front();
		q.pop();
		--left;

		for (int to : graph[v]) {
			--pows[to];
			if (!used[to] && pows[to] < k) {
				used[to] = true;
				q.push(to);
			}
		}
	}

	vector<int> ans(m);

	for (int i = m - 1; i >= 0; --i) {
		ans[i] = left;
		pii e = edges[i];
		if (!used[e.ff] && !used[e.ss]) {
			--pows[e.ff];
			--pows[e.ss];
			graph[e.ff].erase(e.ss);
			graph[e.ss].erase(e.ff);
			if (pows[e.ff] < k) {
				q.push(e.ff);
				used[e.ff] = true;
			}
			if (pows[e.ss] < k) {
				q.push(e.ss);
				used[e.ss] = true;
			}

			while (szof(q)) {
				int v = q.front();
				q.pop();
				--left;

				for (int to : graph[v]) {
					--pows[to];
					if (!used[to] && pows[to] < k) {
						used[to] = true;
						q.push(to);
					}
				}
			}
		}
	}

	for (int num : ans) {
		cout << num << "\n";
	}
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