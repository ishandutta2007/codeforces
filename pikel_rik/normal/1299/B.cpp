#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	map<tuple<long long, int, int>, int> mp;
	for (int i = 0; i < n; i++) {
		int j = (i == 0 ? n - 1 : i - 1);
		int dx = x[i] - x[j], dy = y[i] - y[j];
		int g = __gcd(dx, dy);
		dx /= g, dy /= g;
		if (dx < 0) {
			dx = -dx, dy = -dy;
		}
		long long dist = (long long)(x[i] - x[j]) * (x[i] - x[j]) + (long long)(y[i] - y[j]) * (y[i] - y[j]);
		mp[make_tuple(dist, dx, dy)]++;
	}

	bool similar = true;
	for (auto &[t, c] : mp) {
		similar &= c == 2;
	}
	cout << (similar ? "YES" : "NO") << '\n';
	return 0;
}