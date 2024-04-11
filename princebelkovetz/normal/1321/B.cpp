#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 5e2 + 2;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	map <int, int> dp;
	for (int i = 0; i < n; ++i)
		dp[a[i] - i] += a[i];
	int ans = 0;
	for (auto x : dp) {
		ans = max(x.second, ans);
	}
	cout << ans << '\n';
}