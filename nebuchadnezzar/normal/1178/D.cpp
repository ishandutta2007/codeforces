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

bool is_prime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << "3\n1 2\n2 3\n3 1\n";
		return;
	}

	for (int i = n; i <= n + n / 2; ++i) {
		if (is_prime(i)) {
			set<pii> edges;
			for (int j = 0; j < n; ++j) {
				int a = j;
				int b = (j + 1) % n;
				if (a > b) {
					swap(a, b);
				}
				edges.insert({a, b});
			}
			for (int j = 0; j < i - n; ++j) {
				int a = j;
				int b = j + n / 2;
				edges.insert({a, b});
			}

			assert(szof(edges) == i);
			cout << szof(edges) << endl;
			for (pii e : edges) {
				cout << e.ff + 1 << " " << e.ss + 1 << "\n";
			}
			return;
		}
	}

	assert(false);
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