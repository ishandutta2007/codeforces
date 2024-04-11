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

const int bp = 19;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> arr;
	vector<vector<int>> bits;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		vector<int> have;
		for (int j = 0; j < bp; ++j) {
			if (num & (1 << j)) {
				have.push_back(j);
			}
		}
		bits.push_back(have);
	}

	vector<vector<int>> nearest(bp, vector<int>(bp, INF));
	vector<vector<int>> next(n, vector<int>(bp, INF));

	for (int i = n - 1; i >= 0; --i) {
		for (int j : bits[i]) {
			for (int k : bits[i]) {
				nearest[j][k] = i;
				for (int l = 0; l < bp; ++l) {
					nearest[j][l] = min(nearest[j][l], nearest[k][l]);
				}
			}
		}
		if (szof(bits[i])) {
			for (int j = 0; j < bp; ++j) {
				next[i][j] = nearest[bits[i].front()][j];
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (!arr[a] || !arr[b]) {
			cout << "Fou\n";
		} else {
			// assert(szof(bits[b]));
			// cerr << bits[b].front() << endl;
			if (next[a][bits[b].front()] <= b) {
				cout << "Shi\n";
			} else {
				cout << "Fou\n";
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