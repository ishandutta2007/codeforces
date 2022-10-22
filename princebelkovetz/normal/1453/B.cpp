#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases;
	cin >> testcases;
	while (testcases --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <int> dx(n);
		for (int i = n - 2; i >= 0; --i) {
			dx[i] = dx[i + 1] + abs(a[i] - a[i + 1]);
		}
		int ans = dx[0];
		for (int i = 2; i < n; ++i) {
			int cur = dx[i];
			cur += dx[0] - dx[i - 2];
			cur += abs(a[i] - a[i - 2]);
			ans = min(ans, cur);
		}
		ans = min(ans, dx[1]);
		ans = min(ans, dx[0] - dx[n - 2]);
		cout << ans << '\n';
	}
}