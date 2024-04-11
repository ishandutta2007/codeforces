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
	int n;
	cin >> n;
	vector<int> cost(n);
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
	}
	vector<vector<pii>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	vector<ll> d(n);

	function<ll(int, int)> dfs1 = [&](int v, int p) {
		ll ret = cost[v];
		for (pii to : graph[v]) {
			if (to.ff != p) {
				ll tmp = dfs1(to.ff, v);
				if (tmp >= to.ss) {
					ret = max(ret, tmp - to.ss + cost[v]);
				}
			}
		}
		d[v] = ret;
		return ret;
	};

	ll ans = 0;

	function<void(int, int, ll)> dfs2 = [&](int v, int p, ll best) {
		multiset<ll> st;
		st.insert(best);
		for (pii to : graph[v]) {
			if (to.ff != p) {
				ll tmp = d[to.ff];
				if (tmp >= to.ss) {
					st.insert(tmp - to.ss);
				}
			}
		}
		ans = max(ans, *--st.end() + cost[v]);

		for (pii to : graph[v]) {
			if (to.ff != p) {
				ll tmp = d[to.ff];
				if (tmp >= to.ss) {
					st.erase(st.find(tmp - to.ss));
				}

				ll nbest = 0;
				if (szof(st)) {
					nbest = *--st.end();
				}

				nbest += cost[v];

				nbest = max(nbest - to.ss, 0ll);
				dfs2(to.ff, v, nbest);

				if (tmp >= to.ss) {
					st.insert(tmp - to.ss);
				}
			}
		}
	};

	dfs1(0, 0);
	dfs2(0, 0, 0);

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