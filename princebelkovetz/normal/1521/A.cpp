#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>

using namespace std;
const int mod = 1e9 + 7, root = 325;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int a, b; cin >> a >> b;
		int x = a, y = a * b + a * (b - 1), z = x + y;
		int c1 = 0, c2 = 0;
		if (x % (a * b) == 0) c2++;
		else if (x % a == 0) c1++;
		if (y % (a * b) == 0) c2++;
		else if (y % a == 0) c1++;
		if (z % (a * b) == 0) c2++;
		else if (z % a == 0) c1++;
		if (c2 == 1 and c1 == 2) {
			cout << "YES\n";
			cout << x << ' ' << y << ' ' << z << '\n';
		}
		else cout << "NO\n";
	}
	return 0;
}