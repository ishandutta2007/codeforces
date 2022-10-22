#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	int n, mn = 1e9; cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
		mn = min(a[i], mn);
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; ++i) {
		if (a[i] % mn and a[i] != b[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt-- > 0) {
		solve();
	}
}