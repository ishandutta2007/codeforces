#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		int ans = n;
		for (int i = 1, cur = 1; i < 32; ++i, cur = (cur << 1) + 1) {
			if ((n >> (i - 1)) & 1) 
				ans = min(ans, ((n >> i) << i) + cur / 2);
		}
		cout << ans << '\n';
	}
}