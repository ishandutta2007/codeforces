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

int ask(int type, int v) {
	cout << (char) ('A' + type) << " " << v + 1 << endl;
	int res;
	cin >> res;
	if (res == -1) {
		exit(0);
	}
	return res - 1;
}

void ans(int o) {
	if (o == -1) {
		cout << "C -1" << endl;
	} else {
		cout << "C " << o + 1 << endl;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int k1;
	cin >> k1;
	set<int> my;
	for (int i = 0; i < k1; ++i) {
		int ind;
		cin >> ind;
		my.insert(ind - 1);
	}

	int k2;
	cin >> k2;
	set<int> his;
	for (int i = 0; i < k2; ++i) {
		int ind;
		cin >> ind;
		his.insert(ind - 1);
	}

	int u = ask(1, *his.begin());
	if (my.count(u)) {
		ans(u);
		return;
	}

	function<int(int, int, int, int)> dfs = [&](int v, int p, int target, int last) {
		if (v == target) {
			return last;
		}
		if (my.count(v)) {
			last = v;
		}
		for (int to : graph[v]) {
			if (to != p) {
				int tmp = dfs(to, v, target, last);
				if (tmp != -1) {
					return tmp;
				}
			}
		}
		return -1;
	};

	int v = dfs(*my.begin(), -1, u, -1);
	int tmp = ask(0, v);
	if (his.count(tmp)) {
		ans(v);
	} else {
		ans(-1);
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	int test_count = 1;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}