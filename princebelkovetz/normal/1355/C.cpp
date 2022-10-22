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
	int a, b, c, d, ans = 0;
	cin >> a >> b >> c >> d;
	vector <int> ok(b + c + 2);
	for (int x = a; x <= b; ++x) {
		ok[x + b]++;
		ok[x + c + 1]--;
	}
	for (int i = 1; i < ok.size(); ++i) {
		ok[i] += ok[i - 1];
		//cout << i << " " << ok[i] << endl;
	}
	for (int i = ok.size() - 1; i >= 0; i--) {
		ans += max(0ll, min(d + 1, i) - c) * ok[i];
		//debug(ans);
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