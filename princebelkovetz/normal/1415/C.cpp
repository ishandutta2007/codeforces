#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n, p, k; cin >> n >> p >> k;
		string s; cin >> s;
		int x, y; cin >> x >> y;
		vector <int> cnt(n);
		for (int i = 0; i < n; ++i) {
			if (i >= k) {
				cnt[i] = cnt[i - k] - (s[i - k] == '0');
				continue;
			}
			for (int j = i; j < n; j += k) {
				cnt[i] += (s[j] == '0');
			}
		}
		int ans = 1e18;
		for (int i = p - 1; i < n; ++i) {
			ans = min(ans, y * (i - p + 1) + x * cnt[i]);
		}
		cout << ans << '\n';
	}
}