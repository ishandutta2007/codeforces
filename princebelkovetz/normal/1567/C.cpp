#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 3e6 + 5, bb = 32;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt; cin >> tt;

	map <int, int> cnt;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cnt[i + j]++;
		}
	}

	while (tt --> 0) {
		string s; cin >> s;
		int n = s.size();

		vector <int> a;
		for (int i = n - 1; i >= 0; --i)
			a.push_back(s[i] - '0');

		int ans = 0;
		
		for (int i = 0; i < (1 << n); i += 4) {
			vector <int> cur = a;
			int add = 1;
			for (int j = 0; j < n; ++j) {
				if (i >> (j + 2) & 1) cur[j] += 10, cur[j + 2]--;
				add *= cnt[cur[j]];
			}
			ans += add;
		}
		cout << ans - 2 << '\n';
	}
	return 0;
}