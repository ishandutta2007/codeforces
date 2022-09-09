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
	int n;
	cin >> n;
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	vector<pair<ll, int>> acts;

	for (int i = 0; i < szof(arr) - 1; ++i) {
		acts.push_back({arr[i + 1] - arr[i], -1});
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll l, r;
		cin >> l >> r;
		acts.push_back({r - l + 1, i});
	}

	sort(acts.begin(), acts.end());

	ll sum = 0;
	vector<ll> ans(q);
	ll prev = 0;
	int left = n;
	for (auto p : acts) {
		// cerr << p.ff << " " << p.ss << endl;
		sum += (p.ff - prev) * left;
		prev = p.ff;
		if (p.ss == -1) {
			--left;
		} else {
			ans[p.ss] = sum;
		}
	}

	for (auto num : ans) {
		cout << num << " ";
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