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
	string s; cin >> s;
	int n = s.size();
	vector <int> a(n), pref(n + 1), last(3, -1);
	last[0] = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = (int)s[i] - (int)'1' + 1;
		pref[i + 1] = pref[i] + a[i];
	}
	//for (auto x : pref) cout << x << " ";
	//cout << endl;
	vector <int> dp(n + 1);
	for (int i = 0; i < n; ++i) {
		if (last[pref[i + 1] % 3] != -1) dp[i + 1] = dp[last[pref[i + 1] % 3]] + 1;
		dp[i + 1] = max(dp[i + 1], dp[i]);
		last[pref[i + 1] % 3] = i + 1;
		//debug(i); debug(dp[i + 1])
	}
	cout << dp[n];


}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; t = 1;

	while (t--) {
		solve();
	}
	return 0;
}