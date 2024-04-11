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

const int MAXN = 1e5 + 5;
int type[MAXN];
vector<int> graph[MAXN];

void solve() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	map<int, vector<int>> have;
	for (int i = 0; i < n; ++i) {
		cin >> type[i];
		--type[i];
		have[type[i]].push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<vector<int>> here(n);

	for (auto& p : have) {
		queue<int> q;
		vector<int> dist(n, INF);
		for (auto v : p.ss) {
			dist[v] = 0;
			q.push(v);
		}

		while (szof(q)) {
			int v = q.front();
			q.pop();
			for (int to : graph[v]) {
				if (dist[to] > dist[v] + 1) {
					dist[to] = dist[v] + 1;
					q.push(to);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			here[i].push_back(dist[i]);
		}
	}

	for (int i = 0; i < n; ++i) {
		nth_element(here[i].begin(), here[i].begin() + s - 1, here[i].end());
		cout << accumulate(here[i].begin(), here[i].begin() + s, 0ll) << " ";
	}

	cout << "\n";
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