#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int a, b; cin >> a >> b;
		int ans = mod;
		int l = max(2ll, b), r = a + 1;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			int r1 = m - b, r2 = 0, c = a;
			while (c)
				c /= m, r2++;
			if (r1 > r2) r = m;
			else l = m;
		}
		int st = max(max(2ll, b), l - 10);
		for (int i = st; i < st + 20; ++i) {
			int r1 = i - b, r2 = 0, c = a;
			while (c)
				c /= i, r2++;
			ans = min(ans, r1 + r2);
		}
		cout << ans << '\n';
	}
	return 0;
}