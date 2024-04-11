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
	int n, m = 1e5 + 1, ans = 0; cin >> n;
	vector <int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	vector <int> prime(m + 1);
	for (int i = 0; i < n; ++i) {
		int ok = a[i];
		if (ok == 1) prime[1] = 1;
		for (int j = 2; j * j <= ok; ++j) {
			if (a[i] % j == 0) prime[j]++;
			while (a[i] % j == 0) a[i] /= j;
		}
		if (a[i] != 1) prime[a[i]]++;
	}
	for (int i = 0; i <= m; ++i) ans = max(ans, prime[i]);
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