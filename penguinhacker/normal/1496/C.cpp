#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n; cin >> n;
	vector<int> x, y;
	for (int i = 0; i < 2 * n; ++i) {
		int a, b; cin >> a >> b;
		if (a == 0)
			y.push_back(abs(b));
		else if (b == 0)
			x.push_back(abs(a));
	}
	assert(x.size() == n && y.size() == n);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	double ans = 0;
	for (int i = 0; i < n; ++i)
		ans += sqrt((ll)x[i] * x[i] + (ll)y[i] * y[i]);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}