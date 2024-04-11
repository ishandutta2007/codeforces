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


void solve() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> points;
	map<pii, vector<int>> by_xy;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		points.push_back({x, y, z});
		by_xy[{x, y}].push_back(i);
	}

	vector<bool> removed(n);

	for (auto& v : by_xy) {
		sort(v.ss.begin(), v.ss.end(), [&](int a, int b) {
			return get<2>(points[a]) < get<2>(points[b]);
		});
		for (int i = 0; i + 1 < szof(v.ss); i += 2) {
			cout << v.ss[i] + 1 << " " << v.ss[i + 1] + 1 << "\n";
			removed[v.ss[i]] = removed[v.ss[i + 1]] = true;
		}
	}

	map<int, vector<int>> by_x;
	for (int i = 0; i < n; ++i) {
		if (!removed[i]) {
			by_x[get<0>(points[i])].push_back(i);
		}
	}

	for (auto& v : by_x) {
		sort(v.ss.begin(), v.ss.end(), [&](int a, int b) {
			return get<1>(points[a]) < get<1>(points[b]);
		});
		for (int i = 0; i + 1 < szof(v.ss); i += 2) {
			cout << v.ss[i] + 1 << " " << v.ss[i + 1] + 1 << "\n";
			removed[v.ss[i]] = removed[v.ss[i + 1]] = true;
		}
	}

	vector<int> left;
	for (int i = 0; i < n; ++i) {
		if (!removed[i]) {
			left.push_back(i);
		}
	}

	sort(left.begin(), left.end(), [&](int a, int b) {
		return get<0>(points[a]) < get<0>(points[b]);
	});

	for (int i = 0; i < szof(left); i += 2) {
		cout << left[i] + 1 << " " << left[i + 1] + 1 << "\n";
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