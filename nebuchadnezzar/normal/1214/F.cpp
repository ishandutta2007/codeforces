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
	int m, n;
	cin >> m >> n;
	vector<pii> places;
	vector<int> places_coords;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		places.push_back({x, i});
		places_coords.push_back(x);
	}
	vector<pii> empl;
	vector<int> empl_coords;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		empl.push_back({x, i});
		empl_coords.push_back(x);
	}

	sort(places.begin(), places.end());
	sort(empl.begin(), empl.end());
	sort(places_coords.begin(), places_coords.end());
	sort(empl_coords.begin(), empl_coords.end());

	vector<ll> changes(n + 1);

	for (int i = 0; i < n; ++i) {
		vector<pii> add;
		add.push_back({0, m - places[i].ff});
		int pos = lower_bound(empl_coords.begin(), empl_coords.end(), places[i].ff - m / 2) - empl_coords.begin();
		add.push_back({pos, places[i].ff});
		pos = lower_bound(empl_coords.begin(), empl_coords.end(), places[i].ff) - empl_coords.begin();
		add.push_back({pos, -places[i].ff});
		pos = lower_bound(empl_coords.begin(), empl_coords.end(), places[i].ff + (m + 1) / 2) - empl_coords.begin();
		add.push_back({pos, m + places[i].ff});

		// cerr << "i: " << i << endl;
		// for (auto p : add) {
		// 	cerr << p.ff << " " << p.ss << endl;
		// }

		int cur = 0;
		while (cur < szof(add) - 1 && add[cur + 1].ff <= i) {
			++cur;
		}
		changes[0] += add[cur].ss;
		for (int j = 0; j < 4; ++j) {
			int next = (cur + 1) % 4;
			int tmp = (add[next].ff - i + n) % n;
			if (tmp) {
				changes[tmp] -= add[cur].ss;
				changes[tmp] += add[next].ss;
			}
			cur = next;
		}
		// for (int num : changes) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
	}

	for (int i = 0; i < n; ++i) {
		vector<pii> add;
		add.push_back({0, -empl[i].ff});
		int pos = upper_bound(places_coords.begin(), places_coords.end(), empl[i].ff - (m + 1) / 2) - places_coords.begin();
		add.push_back({pos, empl[i].ff});
		pos = upper_bound(places_coords.begin(), places_coords.end(), empl[i].ff) - places_coords.begin();
		add.push_back({pos, -empl[i].ff});
		pos = upper_bound(places_coords.begin(), places_coords.end(), empl[i].ff + m / 2) - places_coords.begin();
		add.push_back({pos, empl[i].ff});

		// cerr << "i: " << i << endl;
		// for (auto p : add) {
		// 	cerr << p.ff << " " << p.ss << endl;
		// }

		int cur = 0;
		while (cur < szof(add) - 1 && add[cur + 1].ff <= i) {
			++cur;
		}
		changes[0] += add[cur].ss;
		for (int j = 0; j < 4; ++j) {
			int next = (cur - 1 + 4) % 4;
			int tmp = (i - add[cur].ff + 1 + n) % n;
			if (tmp) {
				changes[tmp] -= add[cur].ss;
				changes[tmp] += add[next].ss;
			}
			cur = next;
		}
	}

	ll sum = 0;
	int mem = 0;
	ll best = INFL;
	for (int i = 0; i < n; ++i) {
		sum += changes[i];
		// cerr << i << " " << sum << endl;
		if (sum < best) {
			best = sum;
			mem = i;
		}
	}

	rotate(empl.begin(), empl.begin() + mem, empl.end());
	cout << best << "\n";
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[places[i].ss] = empl[i].ss;
	}

	for (int num : ans) {
		cout << num + 1 << " ";
	}
	cout << "\n";
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