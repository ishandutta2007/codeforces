#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n, m, r, c; cin >> n >> m >> r >> c;
		vector <pair <int, int>> ok = { {1, 1}, {1, m}, {n, 1}, {n, m} };
		int ans = 0;
		for (auto x : ok) {
			ans = max(ans, abs(r - x.first) + abs(c - x.second));
		}
		cout << ans << '\n';
	}
}