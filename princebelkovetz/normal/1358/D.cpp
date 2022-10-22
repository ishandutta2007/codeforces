#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;

void solve() {
	int n, x, mx = 0, ans = 0, cur = 0, l, r, m, ok;
	cin >> n >> x;
	vector <int> d(n), days(n * 2 + 1, 0), hugs(n * 2 + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		d.push_back(d[i]);
		mx = max(mx, d[i]);
	}
	for (int i = n * 2 - 1; i >= 0; i--) {
		days[i] = days[i + 1] + d[i];
		hugs[i] = hugs[i + 1] + d[i] * (d[i] + 1) / 2;
	}
	if (x <= mx) {
		ans = mx * (mx + 1) / 2;
		ans -= (mx - x) * (mx - x + 1) / 2;
		cout << ans; return;
	}
	for (int i = n * 2 - 1; i >= n; i--) {
		cur = 0;
		r = i + 1; l = i - n - 1;
		while (l + 1 < r) {
			m = (l + r) / 2;
			if (days[m] - days[i + 1] >= x) l = m;
			else r = m;
		}
		if (l == i - n - 1) l = r;
		ok = x;
		cur = hugs[l] - hugs[i + 1];
		ok -= (days[l] - days[i + 1]);
		cur -= (-ok) * (-ok + 1) / 2;
		ans = max(ans, cur);
	}
	cout << ans;
	return;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}