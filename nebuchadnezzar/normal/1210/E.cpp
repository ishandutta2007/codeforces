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
	int n, k;
	cin >> n >> k;
	vector<int> order(k);
	iota(order.begin(), order.end(), 0);
	vector<vector<int>> perms;
	map<vector<int>, int> perm_ind;
	do {
		perms.push_back(order);
		perm_ind[order] = szof(perms) - 1;
	} while (next_permutation(order.begin(), order.end()));

	vector<vector<int>> go(szof(perms), vector<int>(szof(perms)));
	vector<int> res(k);
	for (int i = 0; i < szof(perms); ++i) {
		for (int j = 0; j < szof(perms); ++j) {
			for (int q = 0; q < k; ++q) {
				res[perms[j][q]] = perms[i][q];
			}
			go[i][j] = perm_ind[res];
		}
	}

	vector<int> arr;

	for (int i = 0; i < n; ++i) {
		vector<int> cur;
		for (int j = 0; j < k; ++j) {
			int num;
			cin >> num;
			cur.push_back(num - 1);
		}
		arr.push_back(perm_ind[cur]);
	}

	vector<bool> used(szof(perms));
	vector<int> last(szof(perms), n);
	vector<int> order_perms(szof(perms));
	iota(order_perms.begin(), order_perms.end(), 0);
	ll ans = 0;
	vector<int> added;
	vector<int> was;
	vector<int> tmp;
	vector<int> add_perms;
	for (int i = n - 1; i >= 0; --i) {
		last[arr[i]] = i;
		fill(used.begin(), used.end(), 0);
		sort(order_perms.begin(), order_perms.end(), [&](int a, int b) {
			return last[a] < last[b];
		});
		int from = i;
		int cnt = 1;
		used[0] = true;
		was = {0};
		add_perms.clear();
		for (int p : order_perms) {
			if (last[p] == n) {
				break;
			}
			if (used[go[0][p]]) {
				continue;
			}
			add_perms.push_back(p);
			ans += (last[p] - from) * cnt;
			// cerr << i << " " << from << " " << last[p] << " " << cnt << endl;
			while (true) {
				bool changed = false;
				for (int i = 0; i < szof(perms); ++i) {
					if (!used[i]) {
						continue;
					}
					for (int q : add_perms) {
						if (!used[go[i][q]]) {
							used[go[i][q]] = true;
							++cnt;
							changed = true;
						}
					}
				}
				if (!changed) {
					break;
				}
			}
			from = last[p];
		}
		ans += (n - from) * cnt;
		// cerr << i << " " << from << " " << n << " " << cnt << endl;
		// for (int j = 0; j < szof(perms); ++j) {
		// 	if (used[j]) {
		// 		for (int num : perms[j]) {
		// 			cerr << num << " ";
		// 		}
		// 		cerr << endl;
		// 	}
		// }
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