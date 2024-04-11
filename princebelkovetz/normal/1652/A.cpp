#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x < '\n';
#define ld long double
const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int ans = -mod * mod;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) ans = max(ans, a[i] + a[j]);
		}
		cout << ans << '\n';
	}
	
}