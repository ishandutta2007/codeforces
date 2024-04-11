#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <unordered_map>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 200;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

	int n; cin >> n;
	map <int, int> cnt;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	for (int cur = 1; cur < 2e9; cur <<= 1) {
		for (auto x : cnt) {
			if (x.first == cur - x.first)
				ans += x.second * (x.second - 1) / 2;
			if (x.first <= cur - x.first) continue;
			if (cnt.find(cur - x.first) == cnt.end()) continue;
			ans += x.second * cnt[cur - x.first];
		}
	}
	cout << ans << '\n';


    return 0;
}