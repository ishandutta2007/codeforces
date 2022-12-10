//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

#define smin(x, y) x = min(x, y)

void solve() {
	int n, x, y, d;
	cin >> n >> x >> y >> d;
	x--, y--;
	int dif = abs(x - y);
	if (dif % d == 0)
		cout << dif / d << '\n';
	else {
		int ans = INT_MAX;
		if (y % d == 0)
			smin(ans, y / d + (x + d - 1) / d);
		if (y % d == (n - 1) % d)
			smin(ans, (n - 1 - y) / d + (n - 1 - x + d - 1) / d);
		if (ans == INT_MAX)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}