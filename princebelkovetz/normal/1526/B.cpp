#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

constexpr int inf = 1e9 + 7;
void ext_gcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	int rx, ry;
	ext_gcd(b, a % b, rx, ry);
	x = ry, y = rx - a / b * ry;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		cout << (n - (10 * (n + 11)) / 111 * 11 < 0 ? "NO" : "YES") << '\n';

	}
}