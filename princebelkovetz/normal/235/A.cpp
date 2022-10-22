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
	int n, cur,ans = 0; cin >> n;
	for (int i = n; i >= max(n - 5, 1ll); i--) {
		for (int j = n; j >= max(n - 5, 1ll); j--) {
			for (int k = n; k >= max(n - 5, 1ll); k--) {
				cur = i * j / gcd(i, j);
				cur = cur * k / gcd(cur, k);
				ans = max(ans, cur);
			}
		}
	}
	cout << ans << endl;


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