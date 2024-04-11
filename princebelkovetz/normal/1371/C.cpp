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
		int a, b, n, m; cin >> a >> b >> n >> m;
		if (m <= min(a, b) and n <= a + b - m) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}