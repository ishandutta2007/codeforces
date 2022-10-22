#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int n, m, k; cin >> n >> m >> k;
	vector <int> a(n), b(n);
	map <int, int> mp;
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	for (int i = 0; i < n; ++i) {
		int cur = (mp.find(b[i]) == mp.end() ? 0 : mp[b[i]]);
		mp[b[i]] = max(cur, a[i]);
	}
	int cnt = 0;
	while (k --> 0) {
		int x; cin >> x;
		if (mp[b[x - 1]] == a[x - 1]) {
			// bruh
		}
		else cnt++;
	}
	cout << cnt << '\n';
}