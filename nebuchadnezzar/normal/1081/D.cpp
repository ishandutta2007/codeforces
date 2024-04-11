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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> is_special(n);
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		--x;
		is_special[x] = 1;
	}

	vector<pair<int, pii>> edges;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		edges.push_back({w, {a, b}});
	}

	sort(edges.begin(), edges.end());

	vector<int> dsu(n);
	iota(dsu.begin(), dsu.end(), 0);
	vector<int> here = is_special;

	function<int(int)> get_root = [&](int v) {
		int mem = v;
		while (dsu[v] != v) {
			v = dsu[v];
		}
		while (dsu[mem] != mem) {
			int tmp = dsu[mem];
			dsu[mem] = v;
			mem = tmp;
		}
		return v;
	};

	for (auto& e : edges) {
		int a = get_root(e.ss.ff);
		int b = get_root(e.ss.ss);
		if (a != b) {
			dsu[a] = b;
			here[b] += here[a];
			if (here[b] == k) {
				for (int i = 0; i < k; ++i) {
					cout << e.ff << " ";
				}
				cout << "\n";
				return;
			}
		}
	}
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