#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int x, y, k; cin >> x >> y >> k;
		int ans = 0;
		ans += (k * y - 1 + x - 2) / (x - 1);
		int res = (x - 1) * ans - k * y + 1;
		ans += (k - res + x - 1 - 1) / (x - 1);
		cout << ans + k << '\n';
	}
	return 0;
}