#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(8);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int h, c, t; cin >> h >> c >> t;
		if (t <= (h + c) / 2) cout << "2\n";
		else {
			int l = 0, r = 1e9;
			while (l + 1 < r) {
				int m = (l + r) / 2;
				int curtemp = h * (m + 1) + c * m;
				if (curtemp >= t * (2 * m + 1)) l = m;
				else r = m;
			}
			int absR = abs(h * (r + 1) + c * r - t * (2 * r + 1));
			int absL = abs(h * (l + 1) + c * l - t * (2 * l + 1));
			if (absL * (2 * r + 1) <= absR * (2 * l + 1)) cout << 2 * l + 1;
			else cout << 2 * r + 1;
			cout << endl;
		}
	}
	return 0;
}