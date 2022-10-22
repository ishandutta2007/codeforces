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
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
void solve() {
	int n, ans = 0, f, g = 1; cin >> n;
	vector <int> a(n), pref(n + 1), cur(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	map <int, int> ok; ok[0] = 1;
	for (int i = 0; i < n; ++i) {
		cur[i] = cur[max(0ll, i - 1)];
		for (int j = cur[i]; j < n; ++j) {
			if (ok[pref[j + 1]]) break;
			ok[pref[j + 1]] = 1;
			cur[i]++;
		}
		//for (auto x: ok) cout << x.first  << " " << x.second << endl;
		ok[pref[i]]--;
		ans += cur[i] - i;
		//debug(cur[i]); debug(ans);
		// gospodi suka uzhe tri chasa nochi ya zaebalsya debuggat' eto govno
	}
	cout << ans;
	
	



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