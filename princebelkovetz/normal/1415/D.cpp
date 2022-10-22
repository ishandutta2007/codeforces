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
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	if (n >= 60) {
		cout << "1\n";
		return 0;
	}
	vector <int> pref(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = (pref[i] ^ a[i]);
	}
	int ans = -1;
	for (int i = 0; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				int x1 = (pref[j] ^ pref[i]);
				int x2 = (pref[k] ^ pref[j]);
				if (x2 < x1) {
					ans = min(k - i - 2, ans == -1 ? n : ans);
				}
			}
		}
	}
	cout << ans << '\n';

}