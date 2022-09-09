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

vector<int> graph[MAXN];
int last = -1;

int dfs(int v, int p) {
	last = v;
	for (int to : graph[v]) {
		if (to != p) {
			dfs(to, v);
		}
	}
	return 0;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int mem = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (szof(graph[i]) > 2) {
			mem = i;
			++cnt;
		}
	}

	if (cnt > 1) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	cout << szof(graph[mem]) << "\n";
	for (int to : graph[mem]) {
		dfs(to, mem);
		cout << mem + 1 << " " << last + 1 << "\n";
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