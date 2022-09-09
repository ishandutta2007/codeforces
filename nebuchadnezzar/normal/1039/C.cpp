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

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

vector<int> dsu, sz;
vector<pair<int*, int>> history;

int get_root(int v) {
	return dsu[v] == v ? v : dsu[v] = get_root(dsu[v]);
}

bool unite(int a, int b) {
	a = get_root(a);
	b = get_root(b);
	if (a == b) {
		return false;
	}
	if (sz[a] < sz[b]) {
		swap(a, b);
	}
	// history.push_back({&dsu[b], dsu[b]});
	// history.push_back({&sz[a], sz[a]});
	dsu[b] = a;
	if (sz[a] == sz[b]) {
		++sz[a];
	}
	// sz[a] += sz[b];
	return true;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> arrc;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arrc.push_back(num);
	}

	map<ll, vector<pii>> mem;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		mem[arrc[u] ^ arrc[v]].push_back({u, v});
	}

	vector<int> bpows = {1};
	for (int i = 0; i < max(k, n) + 5; ++i) {
		bpows.push_back(mult(bpows.back(), 2));
	}

	int ans = mult(sum(bpows[k], MOD - szof(mem)), bpows[n]);
	dsu = vector<int>(n);
	iota(dsu.begin(), dsu.end(), 0);
	sz = vector<int>(n, 0);

	for (auto& p : mem) {
		int cnt = n;
		for (pii e : p.ss) {
			cnt -= unite(e.ff, e.ss);
		}
		add(ans, bpows[cnt]);
		for (pii e : p.ss) {
			dsu[e.ff] = e.ff;
			dsu[e.ss] = e.ss;
			sz[e.ff] = 0;
			sz[e.ss] = 0;
		}
		/*
		while (szof(history)) {
			*history.back().ff = history.back().ss;
			history.pop_back();
		}
		*/
	}

	cout << ans << "\n";
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