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
#pragma GCC optimize("Ofast")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
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
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	int n, k, ans = 1e9, num1 = 0; cin >> n >> k;
	string s; cin >> s;
	for (auto x : s) if (x == '1') num1++;
	for (int i = 0; i < k; ++i) {
		int curChange = 0;
		for (int j = i; j < n; j += k) {
			if (s[j] == '0') curChange++;
			else curChange--;
			curChange = min(curChange, 0ll);
			ans = min(ans, num1 + curChange);
		}
	}
	cout << ans << endl;

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