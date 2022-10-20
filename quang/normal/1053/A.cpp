#include <bits/stdc++.h>

using namespace std;

long long n, m, k;
int main() {
	cin >> n >> m >> k;
	if ((2ll * n * m) % k != 0) {
		cout << "NO\n";
		return 0;
	}
	if (k == 1) {
		cout << "YES\n";
		cout << 0 << " " << 0 << endl;
		cout << n << " " << 0 << endl;
		cout << 0 << " " << m << endl;
		return 0;
	}
	long long foo = __gcd(n * 2, k);
	if (foo > 1) {
		n *= 2;
		n /= foo;
		k /= foo;
		m /= k;
		cout << "YES\n";
		cout << "0 0\n";
		cout << n << " " << 0 << endl;
		cout << 0 << " " << m << endl;
	} else {
		foo = __gcd(2 * m, k);
		if (foo == 1) {
			cout << "NO\n";
			return 0;
		}
		m *= 2;
		m /= foo;
		k /= foo;
		n /= k;
		cout << "YES\n";
		cout << "0 0\n";
		cout << n << " " << 0 << endl;
		cout << 0 << " " << m << endl;
	}
	return 0;
}