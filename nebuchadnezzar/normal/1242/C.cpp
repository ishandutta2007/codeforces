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
	int k;
	cin >> k;
	vector<vector<int>> inp(k);
	map<ll, pii> where;
	ll tot_sum = 0;
	vector<ll> sum_row;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			where[num] = {i, j};
			inp[i].push_back(num);
			tot_sum += num;
		}
		sum_row.push_back(accumulate(inp[i].begin(), inp[i].end(), 0ll));
	}
	if (tot_sum % k != 0) {
		cout << "No\n";
		return;
	}
	ll in_one = tot_sum / k;

	vector<pii> vars(1 << k, {-1, -1});

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < szof(inp[i]); ++j) {
			int cycle = 0;
			bool ok = true;
			int cur = i;
			int el = j;
			while (true) {
				if (cur < i) {
					ok = false;
					break;
				}
				cycle |= 1 << cur;
				ll left = sum_row[cur] - inp[cur][el];
				ll need = in_one - left;
				if (!where.count(need)) {
					ok = false;
					break;
				}
				auto tmp = where[need];
				if (tmp.ff == i) {
					if (tmp.ss != j) {
						ok = false;
					}
					break;
				}
				if (cycle & (1 << tmp.ff)) {
					ok = false;
					break;
				}
				tie(cur, el) = tmp;
			}
			if (ok) {
				vars[cycle] = {i, j};
			}
		}
	}

	vector<int> dp(1 << k, -1);
	dp[0] = 0;
	int all = (1 << k) - 1;

	for (int mask = 0; mask < 1 << k; ++mask) {
		if (dp[mask] == -1) {
			continue;
		}
		for (int cycle = all & ~mask; cycle; cycle = (cycle - 1) & (all & ~mask)) {
			if (vars[cycle].ff == -1) {
				continue;
			}
			dp[mask | cycle] = cycle;
		}
	}

	if (dp[all] == -1) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	vector<pii> ans(k);
	int cur = all;
	while (cur) {
		int cycle = dp[cur];
		auto [pos, el] = vars[cycle];
		int start = pos;
		while (true) {
			ans[pos].ff = inp[pos][el];
			ans[where[in_one - (sum_row[pos] - inp[pos][el])].ff].ss = pos;
			tie(pos, el) = where[in_one - (sum_row[pos] - inp[pos][el])];
			if (pos == start) {
				break;
			}
		}
		cur ^= cycle;
	}

	for (auto p : ans) {
		cout << p.ff << " " << p.ss + 1 << "\n";
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