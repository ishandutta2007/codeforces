// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
	vector<int> arra;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arra.push_back(num);
	}
	vector<int> arrt;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arrt.push_back(num);
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		return arra[a] < arra[b];
	});

	ll ans = 0;

	multiset<pair<int, ll>> have;
	int prev = -INF;
	for (int ind : order) {
		// cerr << ind << endl;
		while (prev < arra[ind] && szof(have)) {
			auto it = have.end();
			--it;
			// cerr << prev << " " << it->ff << " " << it->ss << endl;
			ans += it->ss + (ll) it->ff * prev;
			have.erase(it);
			++prev;
		}
		prev = arra[ind];
		have.insert({arrt[ind], -arra[ind] * (ll) arrt[ind]});
	}
	while (szof(have)) {
		auto it = have.end();
		--it;
		// cerr << prev << " " << it->ff << " " << it->ss << endl;
		ans += it->ss + (ll) it->ff * prev;
		have.erase(it);
		++prev;
	}

	cout << ans << "\n";
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