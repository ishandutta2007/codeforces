#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

long long x0, y0, ax, ay, bx, by, xs, ys, t;

void Input() {
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
}

void Solve() {
	vector<long long> x(1, x0), y(1, y0);
	long long LIMIT = (1LL << 62) - 1;
	while ((LIMIT - bx) / ax >= x.back() && (LIMIT - by) / ay >= y.back()) {
		x.push_back(ax * x.back() + bx); y.push_back(ay * y.back() + by);
	}

	int n = x.size();
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			long long length = x[j] - x[i] + y[j] - y[i];
			long long dist2Left = abs(xs - x[i]) + abs(ys - y[i]);
			long long dist2Right = abs(xs - x[j]) + abs(ys - y[j]);
			if (length <= t - dist2Left || length <= t - dist2Right) ans = max(ans, j-i+1);
		}
	}

	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}