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
	map<int, int> inp;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		s += num;
		inp[num]++;
	}

	if (szof(inp) == 2) {
		cout << n << "\n";
		return;
	}

	vector<vector<int>> d(s + 1, vector<int>(n + 1));
	for (auto p : inp) {
		for (int i = s; i >= 0; --i) {
			for (int k = 0; k <= n; ++k) {
				if (d[i][k] || (i == 0 && k == 0)) {
					for (int j = 0; j < p.ss && i + (j + 1) * p.ff <= s; ++j) {
						d[i + (j + 1) * p.ff][k + j + 1] = max(d[i + (j + 1) * p.ff][k + j + 1], d[i][k] + 1);
					}
				}
			}
		}
		// for (int num : d) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
	}



	int ans = 0;
	for (auto p : inp) {
		for (int j = 0; j < p.ss; ++j) {
			if (d[(j + 1) * p.ff][j + 1] == 1) {
				ans = max(ans, j + 1);
			}
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