#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int mxN = 1e5 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t--) {
		int n, r, ans = 0; cin >> n >> r;
		if (r < n) ans = r * (r + 1) / 2;
		else ans = (n - 1) * (n) / 2 + 1;
		cout << ans << endl;
	}
	return 0;
}