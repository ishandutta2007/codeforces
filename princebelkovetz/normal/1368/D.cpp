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
//pragma GCC optimize("Ofast")
//pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
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
	int n, m = 0, ans = 0, suma = 0; cin >> n;
	vector <int> a(n), bits;
	for (auto& x : a) {
		cin >> x;
		suma += x;
	}
	while (suma != n) {
		bits.push_back(0);
		suma = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] % 2 == 1) bits[bits.size() - 1]++;
			a[i] /= 2;
			if (!a[i]) suma++;
		}
	}
	for (auto x : bits) m = max(x, m);
	for (int i = 0; i < m; ++i) {
		int cur = 1, ok = 0;
		for (int j = 0; j < bits.size(); ++j) {
			if (bits[j]) {
				bits[j]--;
				ok += cur;
			}
			cur *= 2;
		}
		ans += ok * ok;
	}
	cout << ans;



}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}