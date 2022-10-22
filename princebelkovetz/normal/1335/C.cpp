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
	int n, m = 0; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	set <int> ok; map <int, int> cou;
	for (int i = 0; i < n; ++i) {
		ok.insert(a[i]);
		cou[a[i]]++;
		m = max(m, cou[a[i]]);
	}
	if (m < ok.size()) cout << m << endl;
	else if (m > ok.size()) cout << ok.size() << endl;
	else cout << m - 1 << endl;

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