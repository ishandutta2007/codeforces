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

vector<string> let = {"vv", "o", "vv"};

void solve() {
	string s;
	cin >> s;
	vector<vector<ll>> d(4, vector<ll>(szof(s) + 1));
	d[0][0] = 1;
	for (int i = 0; i < szof(s); ++i) {
		for (int j = 0; j < 4; ++j) {
			d[j][i + 1] += d[j][i];
		}
		for (int j = 0; j < 3; ++j) {
			if (i + 1 >= szof(let[j])) {
				bool ok = true;
				for (int k = 0; k < szof(let[j]); ++k) {
					ok &= let[j][k] == s[i - szof(let[j]) + 1 + k];
				}

				if (ok) {
					d[j + 1][i + 1] += d[j][i - szof(let[j]) + 1];
				}
			}
		}
	}

	cout << d[3][szof(s)] << "\n";
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