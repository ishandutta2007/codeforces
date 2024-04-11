#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
long long n, m, x, y, p;
const unsigned long long nmax = 100500;
long long a[nmax];
long long md(long long x, long long mod) {
	return ((x % mod) + mod) % mod;
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
long long extgcd(long long r1, long long r2, long long& x1, long long& y1, long long& x2, long long& y2, bool first = true) {
	if (r1 < r2) { return extgcd(r1, r2, x1, y1, x2, y2, first = true); }
	if (first) {
		x1 = 1; y1 = 0; x2 = 0; y2 = 1;
	}
}
long long power(long long n, long long x, long long m) {
	if (x % 2 == 1) return (n * power(n, x - 1, m)) % m;
	if (x == 0) return 1;
	long long t = power(n, x / 2, m) % m;
	return(t * t) % m;

}
long long mdiv(long long a, long long b, long long p) {
	return mul(a, power(b, p - 2, p), p);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	cin >> n;
	bool c = false, g = true;
	if (n % 2 == 1) c = true;
	long long cou = 0, z = 0;
	for (long long i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] >= 0) {
			a[i] = -a[i] - 1;
		}
		if (c) z = min(z, a[i]);
	}
	for (long long i = 0; i < n; ++i){
		if (a[i] == z and g) { g = false;  cout << -a[i] - 1 << " "; }
		else cout << a[i] << " ";
	}
	return 0;
}