#include <bits/stdc++.h>
using namespace std;

#define int long long
const double eps = 1e-9;

double go(double c, double m, double p, double v) {
	if (abs(p-1) <= eps) return 1;

	double ans = 0;

	// draw c
	if (c > eps) {
		double vs = min(v, c);
		if (m < eps) {
			ans += c*(1+go(c-vs, m, p+vs, v));
		} else {
			ans += c*(1+go(c-vs, m+vs/2, p+vs/2, v));
		}
	}
	
	// draw m
	if (m > eps) {
		double vs = min(v, m);
		if (c < eps) {
			ans += m*(1+go(c, m-vs, p+vs, v));
		} else {
			ans += m*(1+go(c+vs/2, m-vs, p+vs/2, v));
		}
	}

	// draw p
	ans += p;

	return ans;
}

void solve() {
	double c, m, p, v;
	cin >> c >> m >> p >> v;

	// v goes from 0.1 to 0.9 --> at most 20 times until P reaches 1
	cout << fixed << setprecision(12) << go(c, m, p, v) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve(); 
	}

	return 0;
}