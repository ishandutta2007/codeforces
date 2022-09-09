// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

ll ask(int t, int i, int j, int k) {
	cout << t << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	ll ret;
	cin >> ret;
	return ret;
}

void answer(vector<int> arr) {
	cout << "0 ";
	for (int ind : arr) {
		cout << ind + 1 << " ";
	}
	cout << "\n";
}

void solve() {
	int n;
	cin >> n;
	int next = 1;
	for (int i = 2; i < n; ++i) {
		if (ask(2, 0, next, i) == -1) {
			next = i;
		}
	}
	vector<ll> vals(n);
	for (int i = 1; i < n; ++i) {
		if (i != next) {
			vals[i] = ask(1, 0, next, i);
		}
	}
	int max_pos = max_element(vals.begin(), vals.end()) - vals.begin();
	vector<int> part1, part2;
	for (int i = 1; i < n; ++i) {
		if (i != next && i != max_pos) {
			if (ask(2, 0, i, max_pos) == -1) {
				part2.push_back(i);
			} else {
				part1.push_back(i);
			}
		}
	}
	sort(part1.begin(), part1.end(), [&](int a, int b) {
		return vals[a] < vals[b];
	});
	sort(part2.begin(), part2.end(), [&](int a, int b) {
		return vals[a] > vals[b];
	});
	vector<int> ans = {0, next};
	ans.insert(ans.end(), part1.begin(), part1.end());
	ans.push_back(max_pos);
	ans.insert(ans.end(), part2.begin(), part2.end());
	answer(ans);
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