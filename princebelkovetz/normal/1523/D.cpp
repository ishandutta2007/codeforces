#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
#include <cassert>
#include <random>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#pragma GCC optimize("O3")

mt19937 rnd(33);
constexpr int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int n, m, p; cin >> n >> m >> p;
	vector <string> a(n);
	for (auto& x : a) cin >> x;
	int ans = 0;
	vector <int> all;
	for (int i = 0; i < n; ++i)
		all.push_back(i);
	shuffle(all.begin(), all.end(), rnd);
	string res(m, '0');
	for (int hash_stack = 0; hash_stack < min(n, 67); ++hash_stack) {
		int id = all[hash_stack];
		vector <int> ids;
		for (int i = 0; i < m; ++i)
			if (a[id][i] == '1')
				ids.push_back(i);
		int sz = ids.size();
		vector <int> cnt(1 << sz);
		for (int i = 0; i < n; ++i) {
			int cur = 0;
			for (int j = 0; j < sz; ++j) {
				if (a[i][ids[j]] == '1')
					cur += (1 << j);
			}
			cnt[cur]++;
		}
		for (int i = 1; i < (1 << sz); ++i) {
			for (int j = (i + 1) | i; j < (1 << sz); j = (j + 1) | i)
				cnt[i] += cnt[j];
		}
		vector <int> bits(1 << sz);
		int mask = 0;
		for (int i = 0; i < (1 << sz); ++i) {
			bits[i] = (bits[i >> 1] + (i & 1));
			if (cnt[i] * 2 >= n and bits[i] > bits[mask]) {
				mask = i;
			}
		}
		if (bits[mask] > ans) {
			ans = bits[mask];
			string get(m, '0');
			for (int i = 0; i < sz; ++i) {
				if ((mask >> i) & 1)
					get[ids[i]] = '1';
			}
			res = get;
		}
	}
	cout << res << '\n';

}