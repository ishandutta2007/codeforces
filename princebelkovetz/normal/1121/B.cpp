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
	int n; cin >> n;
	map <int, int> mp;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			mp[a[i] + a[j]]++;
		}
	}
	int ans = 0;
	for (auto& x : mp) {
		ans = max(ans, x.second);
	}
	cout << ans << '\n';
}