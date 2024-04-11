#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		map <int, vector <int>> ids;
		for (int i = 0; i < n; ++i)
			ids[a[i]].push_back(i);
		int ans = 0;
		for (auto& x : ids) {
			int cur = 0;
			for (auto& y : x.second) {
				ans += cur * (n - y);
				cur += y + 1;
			}
		}
		cout << ans << '\n';
	}
}