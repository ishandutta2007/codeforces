#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	if (n % 2) {
		cout << "NO\n"; exit(0);
	}

	vector<long long> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i] *= 2; y[i] *= 2;
	}

	int m = n/2;
	long long px = (x[0] + x[m])/2;
	long long py = (y[0] + y[m])/2;

	for (int i = 0; i < m; i++) {
		long long ppx = (x[i] + x[i+m])/2;
		long long ppy = (y[i] + y[i+m])/2;

		if (px != ppx) {
			cout << "NO\n"; exit(0);
		}
		if (py != ppy) {
			cout << "NO\n"; exit(0);
		}
	}
	cout << "YES\n";

	return 0;
}