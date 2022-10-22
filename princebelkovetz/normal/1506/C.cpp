#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		string s, t;
		cin >> s >> t;
		int n = s.size(), m = t.size();
		int ans = n + m;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					for (int f = k; f < m; ++f) {
						if (s.substr(i, j - i + 1) == t.substr(k, f - k + 1))
							ans = min(ans, n - (j - i + 1) + m - (f - k + 1));
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}