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
	if (b < 0) return gcd(a, -b);
	if (a < 0) return gcd(-a, b);
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	int n, m = 0,sum = 0; cin >> n;
	vector <int> a(n);
	for (auto& x : a) {
		cin >> x;
		m = max(m, x);
		sum += x;
	}
	sum += n - 2;
	cout << max(m, sum / (n - 1)) << endl;
	

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