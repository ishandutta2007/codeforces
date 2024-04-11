#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
ld eps = 1e-9;
ld rec(ld c, ld m, ld p, ld v, int len) {
	ld ans = m * len;
	len++;
	if (c > eps) {
		if (c <= v) {
			if (p > eps) {
				ans += c * rec(0, m + c / 2, p + c / 2, v, len);
			}
			else {
				ans += c * rec(0, m + c, 0, v, len);
			}
		}
		else {
			if (p > eps) {
				ans += c * rec(c - v, m + v / 2, p + v / 2, v, len);
			}
			else {
				ans += c * rec(c - v, m + v, 0, v, len);
			}
		}
	}
	if (p > eps) {
		if (p <= v) {
			if (c > eps) {
				ans += p * rec(c + p / 2, m + p / 2, 0, v, len);
			}
			else {
				ans += p * rec(0, m + p, 0, v, len);
			}
		}
		else {
			if (c > eps) {
				ans += p * rec(c + v / 2, m + v / 2, p - v, v, len);
			}
			else {
				ans += p * rec(0, m + v, p - v, v, len);
			}
		}
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt--) {
		ld c, m, p, v;
		cin >> c >> m >> p >> v;
		cout << rec(c, p, m, v, 1) << '\n';
	}
	return 0;
}