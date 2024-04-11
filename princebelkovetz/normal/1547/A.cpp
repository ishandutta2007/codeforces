#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int a[2], b[2], f[2];
		cin >> a[0] >> a[1] >> b[0] >> b[1] >> f[0] >> f[1];
		if (a[0] == b[0]) {
			cout << abs(a[1] - b[1]) + 2 * (f[0] == a[0] and min(a[1], b[1]) < f[1] and max(a[1], b[1]) > f[1]);
		}
		else if (a[1] == b[1]) {
			cout << abs(a[0] - b[0]) + 2 * (f[1] == a[1] and min(a[0], b[0]) < f[0] and max(a[0], b[0]) > f[0]);
		}
		else {
			cout << abs(a[1] - b[1]) + abs(a[0] - b[0]);
		}
		cout << '\n';
	}
	return 0;
}