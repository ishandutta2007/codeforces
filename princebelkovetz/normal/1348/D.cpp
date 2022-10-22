
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
	long long n, cou = 1, j = 1, i = 0;
	vector <long long> a;
	cin >> n;
	while (j <= n) {
		a.push_back(j);
		n -= j;
		j *= 2;
	}
	if (n != 0) {
		a.push_back(n);
		sort(a.begin(), a.end());
	}
	cout << a.size() - 1 << '\n';
	for (long long i = 0; i < a.size() - 1; ++i) {
		cout << a[i + 1] - a[i] << " ";
	}
	cout << endl;
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
	
}