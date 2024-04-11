#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <iomanip>
#include <map>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
const int mxN = 2e5 + 2;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, mx = 0; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i], mx = max(mx, a[i]);
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i and a[i] == a[i - 1]) continue;
		int h = mx / a[i] * a[i];
		long long res = 0; 
		int last = 0;
		for (int j = h; j >= a[i]; j -= a[i]) {
			int l = i, r = n;
			while (l + 1 < r) {
				int m = (l + r) / 2;
				if (a[m] < j) l = m;
				else r = m;
			}
			res += (long long) j * (n - r - last);
			last = n - r;
		}
		ans = max(ans, res + a[i]);
	}
	cout << ans << '\n';
	return 0;
}