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
long long mul(long long x, long long y, long long mod) {
	return md(md(x, mod) * md(y, mod), mod);
}
void solve() {
	long long n, x, t;
	bool f = true;
	cin >> n;
	vector <long long> a(n);
	vector <long long> b(n, 0);
	for (long long i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (long long i = 0; i < n; ++i) {
		x = 0 - a[i];
		if (md(x, n) != i) {
			x += md((n - md(x, n) + i), n);
		}
		b[x + a[md(x, n)]]++;
	}
	for (long long j = 0; j < n; ++j) {
		if (b[j] != 1) { f = false; break; }
	}
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
 
	
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	long t;
	cin >> t;
	while (t--) solve();
	return 0;
}