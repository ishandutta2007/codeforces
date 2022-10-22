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
		int n, k; cin >> n >> k;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int ans = 1e9 + 7;
		for (int i = 1; i <= 100; ++i) {
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				if (a[j] != i)
					cur++, j += k - 1;
			}
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
}