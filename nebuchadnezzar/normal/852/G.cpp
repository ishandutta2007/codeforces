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

const int P = 239;

void solve() {
	int n, m;
	cin >> n >> m;
	unordered_map<ull, int> cnt;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ull h = 0;
		for (char c : s) {
			h = h * P + c;
		}
		cnt[h]++;
		// cerr << h << endl;
	}
	unordered_set<ull> used;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		vector<int> positions;
		int vars = 1;
		for (int j = 0; j < szof(s); ++j) {
			if (s[j] == '?') {
				positions.push_back(j);
				vars *= 6;
			}
		}
		ll ans = 0;
		used.clear();
		for (int mask = 0; mask < vars; ++mask) {
			ull cur = 0;
			int cnt_pos = 0;
			int tmp = mask;
			for (int ind = 0; ind < szof(positions); ++ind) {
				while (cnt_pos < positions[ind]) {
					cur = cur * P + s[cnt_pos++];
				}
				if (tmp % 6) {
					cur = cur * P + 'a' - 1 + tmp % 6;
				}
				++cnt_pos;
				tmp /= 6;
			}
			while (cnt_pos < szof(s)) {
				cur = cur * P + s[cnt_pos++];
			}
			// cerr << cur << endl;
			if (used.insert(cur).ss) {
				ans += cnt[cur];
			}
		}
		cout << ans << "\n";
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