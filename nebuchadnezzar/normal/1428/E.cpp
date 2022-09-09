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

ll calc(int l, int q) {
	int sh_l = l / q;
	int amount_sh = q - l % q;
	ll ret = (ll) amount_sh * sh_l * sh_l;
	int l_l = sh_l + 1;
	int amount_l = q - amount_sh;
	ret += (ll) amount_l * l_l * l_l;
	// cerr << l << " " << q << " " << sh_l << " " << amount_sh << " " << l_l << " " << amount_l << endl;
	return ret;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	ll cur_sum = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		cur_sum += (ll) num * num;
	}

	vector<int> parts(n, 1);
	set<pair<ll, int>> changes;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > parts[i]) {
			changes.insert({calc(arr[i], parts[i]) - calc(arr[i], parts[i] + 1), i});
		}
	}

	for (int i = n; i < k; ++i) {
		auto p = *--changes.end();
		// cerr << i << " " << p.ff << " " << p.ss << endl;
		cur_sum -= p.ff;
		changes.erase(--changes.end());
		parts[p.ss]++;
		if (arr[p.ss] > parts[p.ss]) {
			changes.insert({calc(arr[p.ss], parts[p.ss]) - calc(arr[p.ss], parts[p.ss] + 1), p.ss});
		}
	}

	cout << cur_sum << "\n";
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