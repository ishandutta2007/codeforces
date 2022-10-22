#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
//pragma GCC optimize("Ofast")
//pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#include <queue>
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

void solve() {
	int n, ans = 0; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		ans = max(ans, a[i]);
		for (int j = i; j < n; ++j) {
			ans = max(ans, a[i] | a[j]);
			for (int k = j; k < n; ++k) {
				ans = max(ans, (a[i] | a[j]) | a[k]);
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}