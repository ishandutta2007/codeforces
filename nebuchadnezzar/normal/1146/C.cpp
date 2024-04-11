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

int ask(vector<int> part1, vector<int> part2) {
	cout << szof(part1) << " " << szof(part2) << " ";
	for (int v : part1) {
		cout << v + 1 << " ";
	}
	for (int v : part2) {
		cout << v + 1 << " ";
	}
	cout << endl;
	int ret;
	cin >> ret;
	return ret;
}

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; ; ++i) {
		vector<int> part1, part2;
		for (int j = 0; j < n; ++j) {
			if ((j >> i) & 1) {
				part1.push_back(j);
			} else {
				part2.push_back(j);
			}
		}
		if (!szof(part1) || !szof(part2)) {
			break;
		}
		ans = max(ans, ask(part1, part2));
	}
	cout << "-1 " << ans << endl;
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}