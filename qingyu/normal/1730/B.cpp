#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	cout << fixed << setprecision(10);
	for (int Case = 1; Case <= T; ++Case) {
		int n;
		cin >> n;
		vector<int> x(n), t(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}	
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
		}
		double l = 0, r = 1e9;
		double pos = -1;
		auto check = [&](double mid) {
			double L = -1e9, R = 1e9;
			for (int i = 0; i < n; ++i) {
				if (t[i] > mid) return false;
				double delta = mid - t[i];
				L = max(L, x[i] - delta);
				R = min(R, x[i] + delta);
			}
			if (L <= R) {
				pos = (L + R) / 2;
				return true;
			}
			return false;
		};
		for (int _ = 0; _ < 100; ++_) {
			const double mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid;
		}
		cout << pos << '\n';
	}
}