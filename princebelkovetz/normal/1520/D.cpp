#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		map <int, int> cnt;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			cnt[a[i] - i]++;
		}
		for (auto x : cnt)
			ans += x.second * (x.second - 1) / 2;
		cout << ans << '\n';
	}
	return 0;
}