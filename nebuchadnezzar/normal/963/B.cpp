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

vector<vector<int>> graph;
vector<pii> d;

int dfs(int v, int p) {
	int cnt = 0;
	int cnt0 = 0, cnt1 = 0, cnt01 = 0;
	for (int to : graph[v]) {
		if (to != p) {
			dfs(to, v);
			++cnt;
			if (d[to].ff == 0 && d[to].ss == 1) {
				++cnt1;
			} else if (d[to].ff == 1 && d[to].ss == 0) {
				++cnt0;
			} else if (d[to].ff == 1 && d[to].ss == 1) {
				++cnt01;
			}
		}
	}

	if (cnt0 + cnt1 + cnt01 < cnt) {
		return 0;
	}

	if (cnt % 2 == 0) {
		if (cnt1 % 2 == 0 || (cnt1 % 2 == 1 && cnt01)) {
			d[v].ff = 1;
		}
		if (cnt1 % 2 == 1 || (cnt1 % 2 == 0 && cnt01)) {
			d[v].ss = 1;
		}
	} else {
		if (cnt1 % 2 == 1 || (cnt1 % 2 == 0 && cnt01)) {
			d[v].ff = 1;
		}
		if (cnt1 % 2 == 0 || (cnt1 % 2 == 1 && cnt01)) {
			d[v].ss = 1;
		}
	}
	return 0;
}

int build_ans(int v, int p, int t) {
	vector<int> t0, t1, t01;
	int cnt = 0;
	for (int to : graph[v]) {
		if (to != p) {
			++cnt;
			if (d[to].ff == 0 && d[to].ss == 1) {
				t1.push_back(to);
			} else if (d[to].ff == 1 && d[to].ss == 0) {
				t0.push_back(to);
			} else if (d[to].ff == 1 && d[to].ss == 1) {
				t01.push_back(to);
			}
		}
	}

	if ((cnt % 2 == 0 && (((t == 0 && szof(t1) % 2 == 0)) || (t == 1 && szof(t1) % 2 == 1))) || 
		(cnt % 2 == 1 && (((t == 0 && szof(t1) % 2 == 1)) || (t == 1 && szof(t1) % 2 == 0)))) {
		for (int u : t1) {
			build_ans(u, v, 1);
		}
		cout << v + 1 << "\n";
		for (int u : t0) {
			build_ans(u, v, 0);
		}
		for (int u : t01) {
			build_ans(u, v, 0);
		}
	} else {
		for (int u : t1) {
			build_ans(u, v, 1);
		}
		build_ans(t01.back(), v, 1);
		t01.pop_back();
		cout << v + 1 << "\n";
		for (int u : t0) {
			build_ans(u, v, 0);
		}
		for (int u : t01) {
			build_ans(u, v, 0);
		}
	}

	return 0;
}

void solve() {
	int n;
	cin >> n;
	graph = vector<vector<int>>(n);
	d = vector<pii>(n);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		if (p != -1) {
			graph[i].push_back(p);
			graph[p].push_back(i);
		}
	}

	dfs(0, 0);

	if (!d[0].ff) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		build_ans(0, 0, 0);
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