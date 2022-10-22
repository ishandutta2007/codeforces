#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n, a, b; cin >> n >> a >> b;
		bool c = false;
		if (a == 1) {
			c = ((n - 1) % b == 0);
		}
		else {
			int x = 1;
			while (x <= n) {
				c = c || (((n - x) % b) == 0);
				x *= a;
			}
		}
		cout << (c ? "YES" : "NO") << '\n';
	}
	return 0;
}