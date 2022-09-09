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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> have(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if ((b - a + n) % n * 2 > n) {
			swap(a, b);
		}
		have[(b - a + n) % n].push_back(a);
		if ((b - a + n) % n * 2 == n) {
			have[(b - a + n) % n].push_back(b);
		}
	}

	int res = 1;

	for (int i = 0; i < n; ++i) {
		if (!szof(have[i])) {
			continue;
		}
		if (szof(have[i]) == 1) {
			res = n;
			continue;
		}
		sort(have[i].begin(), have[i].end());
		vector<int> tmp;
		for (int j = 0; j < szof(have[i]); ++j) {
			int next = (j + 1) % szof(have[i]);
			tmp.push_back((have[i][next] - have[i][j] + n) % n);
		}

		vector<int> z(szof(tmp));
		int l = 0, r = 0;
		int shift = szof(tmp);
		for (int j = 1; j < szof(tmp); ++j) {
			if (r > j) {
				z[j] = min(r - j, z[j - l]);
			}
			while (j + z[j] < szof(tmp) && tmp[z[j]] == tmp[j + z[j]]) {
				++z[j];
			}
			if (j + z[j] > r) {
				l = j;
				r = j + z[j];
			}
			if (j + z[j] == szof(tmp) && szof(tmp) % j == 0) {
				shift = j;
				break;
			}
		}

		int sum = 0;
		for (int j = 0; j < shift; ++j) {
			sum += tmp[j];
		}

		res = (ll) res * sum / __gcd(res, sum);
	}

	if (res < n) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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