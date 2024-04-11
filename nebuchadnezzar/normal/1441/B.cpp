// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct value {
	int steps, flips;
	value(int steps_, int flips_) : steps(steps_), flips(flips_) {}

	bool operator<(value const& other) const {
		if (flips == other.flips) {
			return steps < other.steps;
		}
		if (flips > 60 || other.flips > 60) {
			return flips < other.flips;
		}
		return steps + (1ll << flips) - 1 < other.steps + (1ll << other.flips) - 1;
	}
};

const int MOD = 998'244'353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back({b, 0});
		graph[b].push_back({a, 1});
	}
	const int MAXF = 30;
	vector<vector<value>> dist(MAXF, vector<value>(n, value(INF, INF)));
	dist[0][0] = {0, 0};
	set<pair<value, pii>> have;
	have.insert({value(0, 0), {0, 0}});
	while (szof(have)) {
		auto [cd, p] = *have.begin();
		have.erase(have.begin());
		for (auto to : graph[p.ff]) {
			pii act_to = {to.ff, p.ss};
			value new_d = cd;
			if (to.ss == p.ss % 2) {
				new_d.steps++;
			} else {
				++act_to.ss;
				new_d.flips++;
				new_d.steps++;
			}
			if (act_to.ss >= MAXF) {
				act_to.ss -= 2;
			}
			if (new_d < dist[act_to.ss][act_to.ff]) {
				have.erase({dist[act_to.ss][act_to.ff], act_to});
				dist[act_to.ss][act_to.ff] = new_d;
				have.insert({dist[act_to.ss][act_to.ff], act_to});
			}
		}
	}

	value ans = dist[0][n - 1];
	for (int i = 1; i < MAXF; ++i) {
		if (dist[i][n - 1] < ans) {
			ans = dist[i][n - 1];
		}
	}

	// cerr << ans.steps << " " << ans.flips << endl;

	int ans_mod = ans.steps;
	add(ans_mod, mpow(2, ans.flips));
	add(ans_mod, MOD - 1);
	cout << ans_mod << "\n";
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