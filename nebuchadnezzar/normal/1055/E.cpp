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
	int n, s, m, k;
	cin >> n >> s >> m >> k;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<int> from(n, INF);

	for (int i = 0; i < s; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		for (int j = l; j < r; ++j) {
			from[j] = min(from[j], l);
		}
	}

	int l = 0, r = INF;
	vector<int> cur_arr(n), pref(n + 1);
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	while (r - l > 1) {
		int mid = (l + r) / 2;
		for (int i = 0; i < n; ++i) {
			cur_arr[i] = arr[i] > mid;
			pref[i + 1] = pref[i] + (cur_arr[i] == 0);
		}

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				d[i][j] = 0;
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (from[i] <= i) {
					d[i + 1][j + 1] = max(d[i + 1][j + 1], d[from[i]][j] + pref[i + 1] - pref[from[i]]);
				}
				d[i + 1][j + 1] = max(d[i + 1][j + 1], max(d[i][j + 1], d[i + 1][j]));
			}
		}

		if (d[n][m] >= k) {
			r = mid;
		} else {
			l = mid;
		}
	}

	if (r == INF) {
		cout << "-1\n";
	} else {
		cout << r << "\n";
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