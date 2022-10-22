#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
#define map unordered_map
const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;

		int ans = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (j - i + 1 < 3) {
					ans++;
					continue;
				}
				bool ok = true;
				for (int a1 = i; a1 <= j; ++a1) {
					for (int a2 = a1 + 1; a2 <= j; ++a2) {
						for (int a3 = a2 + 1; a3 <= j; ++a3) {
							if (a[a1] >= a[a2] and a[a2] >= a[a3]) ok = false;
							if (a[a1] <= a[a2] and a[a2] <= a[a3]) ok = false;
						}
					}
				}
				ans += ok;
				if (!ok) break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}