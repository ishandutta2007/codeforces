#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <cassert>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	int ok = 0;
	for (int i = 0; i < n; ++i)
		ok = gcd(a[i], ok);
	if (ok == a[0]) {
		cout << 2 * n - 1 << '\n';
		cout << a[0] << ' ';
		for (int i = 1; i < n; ++i) {
			cout << a[i] << ' ' << a[0] << ' ';
		}
		cout << '\n';
	}
	else cout << "-1\n";
	return 0;
}