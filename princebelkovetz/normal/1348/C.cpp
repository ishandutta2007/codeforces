
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
long long md(long long a, long long m) {
	return ((a % m + m) % m);
}
long long add(long long x, long long y, long long mod) {
	return md(md(x, mod) + md(y, mod), mod);
}
long long sub(long long x, long long y, long long mod) {
	return md(md(x, mod) - md(y, mod), mod);
}
void solve() {
	long long n, k;
	string d;

	cin >> n >> k >> d;
	sort(d.begin(), d.end());
	if (k == 1) cout << d << endl;
	else if (d[k - 1] != d[0]) cout << d[k - 1] << endl;
	else {
		string x;
		x += d[0];
		if (d[k] == d[n - 1]) {
			if (n % k != 0) {
				for (long long i = 0; i < (n) / k; ++i) {
					x += d[n - 1];
				}
			}
			else {
				for (long long i = 0; i < (n) / k - 1; ++i) {
					x += d[n - 1];
				}
			}

		}
		else {
			for (long long i = k; i < n; ++i) {
				x += d[i];
			}
		}
		cout << x << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}