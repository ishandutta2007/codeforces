#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
//#pragma GCC optimize("Ofast")
//#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
int gcd(int a, int b) {
	if (b < 0) return gcd(a, -b);
	if (a < 0) return gcd(-a, b);
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	int ans = 0, cur = 0, ok = 0, ans2 = 0, cur2 = 0;
	for (int i = 0; i < n; i += 2) {
		ok += a[i];
		cur += a[min(i + 1, n - 1)] - a[i];
		cur = max(cur, 0ll);
		ans = max(cur, ans);
	}
	for (int i = 1; i < n; i += 2) {
		cur2 += a[i] - a[min(i + 1, n - 1)];
		cur2 = max(cur2, 0ll);
		ans2 = max(ans2, cur2);
	}
	cout << max(ans, ans2) + ok << endl;
	
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}