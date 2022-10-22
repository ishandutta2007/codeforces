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

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	map <int, int> m;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		m[x]++;
	}
	int mxn = 1e5 + 1;
	vector <int> dp(mxn);
	dp[0] = 0;
	if (m.find(1) != m.end()) dp[1] = m[1];
	else dp[1] = 0;
	for (int i = 2, x = 0; i < mxn; ++i) {
		x = 0;
		if (m.find(i) != m.end()) x = m[i];
		dp[i] = max(dp[i - 1], dp[i - 2] + x * i);
	}
	cout << dp[mxn - 1];
}