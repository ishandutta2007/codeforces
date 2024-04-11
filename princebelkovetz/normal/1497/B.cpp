#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define int long long 
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int tt; cin >> tt;
	while (tt--) {
		int n, m; cin >> n >> m;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		map <int, int> ok;
		for (auto& x : a) {
			ok[x % m]++;
		}
		int ans = 0;
		for (auto x : ok) {
			if (!x.second) continue;
			if (2 * x.first == m) {
				ans++;
			}
			else if (x.first) {
				int n = x.second, s = ok[m - x.first];
				if (s == n) ans++;
				else {
					int mn = min(s, n);
					s -= mn, n -= mn;
					ans += s + n;
				}
				ok[m - x.first] = 0;
			}
			else ans++;
		}
		cout << ans << '\n';
	}
}