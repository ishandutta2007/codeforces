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

const int MAXN = 3e5 + 5;
vector<int> graph[MAXN];
int dist[MAXN];
int from[MAXN];

int amount_v = 0;
int amount_e = 0;
vector<int> visited;
bool used[MAXN];
int n, m;

int dfs(int v) {
	//cerr << v << endl;
	visited.push_back(v);
	++amount_v;
	used[v] = true;
	amount_e += szof(graph[v]);
	for (int to : graph[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
	return 0;
}

vector<int> get_path(int s, int t) {
	fill(dist, dist + n, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (szof(q)) {
		int v = q.front();
		q.pop();
		for (int to : graph[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				from[to] = v;
				q.push(to);
			}
		}
	}

	assert(dist[t] < INF);
	vector<int> path;
	int cur = t;
	while (cur != s) {
		path.push_back(cur);
		cur = from[cur];
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	return path;
}

void solve() {
	cin >> n >> m;
	set<pii> edges;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		edges.insert({a, b});
		edges.insert({b, a});
	}
	queue<int> q;
	q.push(0);
	fill(dist, dist + n, INF);
	fill(from, from + n, -1);
	dist[0] = 0;
	while (szof(q)) {
		int v = q.front();
		q.pop();
		for (int to : graph[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				from[to] = v;
				q.push(to);
			}
		}
	}

	if (dist[n - 1] == 1) {
		cout << "1\n" << 1 << " " << n << "\n";
		return;
	}

	if (dist[n - 1] == 2) {
		cout << "2\n";
		cout << 1 << " " << from[n - 1] + 1 << " " << n << "\n";
		return;
	}

	if (dist[n - 1] == 3) {
		cout << "3\n";
		cout << 1 << " " << from[from[n - 1]] + 1 << " " << from[n - 1] + 1 << " " << n << "\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (dist[i] == 2) {
			cout << "4\n";
			cout << 1 << " " << from[i] + 1 << " " << i + 1 << " " << 1 << " " << n << "\n";
			return;
		}
	}

	for (int to : graph[0]) {
		graph[to].erase(find(graph[to].begin(), graph[to].end(), 0));
	}

	for (int i = 1; i < n; ++i) {
		if (dist[i] < INF && !used[i]) {
			amount_v = 0;
			amount_e = 0;
			visited.clear();
			dfs(i);
			//cerr << i << " " << amount_v << " " << amount_e << endl;
			if ((ll) amount_v * (amount_v - 1) != amount_e) {
				for (int u : visited) {
					for (int v : visited) {
						if (u != v && !edges.count({u, v})) {
							vector<int> path = get_path(u, v);
							assert(szof(path) >= 3);
							cout << "5\n";
							cout << 1 << " " << path[0] + 1 << " " << path[1] + 1 << " " << path[2] + 1 << " " << path[0] + 1 << " " << n << "\n";
							return;
						}
					}
				}
			}
		}
	}

	cout << "-1\n";
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