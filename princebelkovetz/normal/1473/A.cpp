#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n, d; cin >> n >> d;
		vector <int> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		int mn = 1e9, mx = 0;
		for (int i = 0; i < n; ++i) {
			mx = max(mx, a[i]);
			for (int j = i + 1; j < n; ++j) {
				mn = min(mn, a[i] + a[j]);
			}
		}
		cout << ((mn <= d or mx <= d) ? "YES" : "NO") << '\n';

	}
	return 0;
}