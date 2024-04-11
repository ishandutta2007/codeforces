#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#pragma GCC optimize("O3")
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, mx = 0; cin >> n;
	vector <int> a(n);
	for (auto& x : a) 
		cin >> x, mx = max(mx, x);
	vector <bool> have(2 * mx + 1);
	for (auto& x : a)
		have[x] = 1;
	vector <int> rx(2 * mx + 1);
	int last = 0, ans = 0;
	for (int i = 1; i <= 2 * mx; ++i) {
		rx[i] = last;
		if (have[i]) last = i;
	}
	for (int i = 1; i <= mx; ++i) {
		int x = i;
		if (!have[x]) continue;
		for (int i = x; i <= 2 * mx - x; i += x) {
			if (rx[i + x] >= i)
				ans = max(ans, rx[i + x] - i);
		}
	}
	cout << ans << '\n';
}