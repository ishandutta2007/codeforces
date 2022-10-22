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
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n, ans = 0; cin >> n;
		for (int i = 1; i <= 9; ++i) {
			int cur = i;
			while (cur <= n) {
				ans++, cur = cur * 10 + i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}