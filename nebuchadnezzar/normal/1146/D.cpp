// Created by Nikolay Budin

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
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int m, a, b;
	cin >> m >> a >> b;
	vector<int> dist(a, INF);
	vector<int> largest(a, INF);
	largest[0] = 0;
	dist[0] = 0;
	set<pii> st;
	st.insert({0, 0});
	while (szof(st)) {
		int x = st.begin()->ff;
		int v = x % a;
		st.erase(st.begin());
		if (x >= b) {
			int to = (x - b) % a;
			if (dist[to] > x - b) {
				st.erase({dist[to], to});
				dist[to] = x - b;
				largest[to] = max(largest[v], x);
				st.insert({dist[to], to});
			}
		} else {
			ll val = (x + (ll) (b - x + a - 1) / a * a);
			int to = (val - b) % a;
			if (dist[to] > val - b) {
				st.erase({dist[to], to});
				dist[to] = val - b;
				largest[to] = max(largest[v], (int) val);
				st.insert({dist[to], to});
			}
		}
	}

	ll ans = 0;

	for (int i = 0; i < a; ++i) {
		if (dist[i] > m || largest[i] > m) {
			continue;
		}
		int from = largest[i];
		int l = dist[i];
		int from_val = (from + 1 - l + a - 1) / a;
		int to_val = (m + 1 - l + a - 1) / a;
		if (to_val == from_val) {
			ans += (ll) (m - from + 1) * from_val;
		} else {
			int nfrom = l + (from - l + a - 1) / a * a;
			ans += (ll) (nfrom - from) * from_val;
			int nfrom_val = (nfrom + 1 - l + a - 1) / a;
			int nto = l + (m - l) / a * a;
			int nto_val = (nto - l + a - 1) / a;
			ans += (ll) (nto - nfrom) * (nfrom_val + nto_val) / 2;
			ans += (ll) (m - nto + 1) * to_val;
		}
	}

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