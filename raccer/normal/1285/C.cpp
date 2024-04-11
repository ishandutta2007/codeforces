#include <bits/stdc++.h>
using namespace std;
int main () {
	long long x; cin >> x;
	vector <long long> fac;
	for (long long i = 2; i * i <= x; i++) {
		if (x % i) continue;
		long long tmp = 1;
		while (x % i == 0) x /= i, tmp *= i;
		fac.push_back(tmp);
	}
	if (x > 1) fac.push_back(x);
	long long aa = 0x3f3f3f3f3f3f3f3f, bb = 0x3f3f3f3f3f3f3f3f;
	for (int mask = 0; mask < (1 << fac.size()); mask++) {
		long long a = 1, b = 1;
		for (int i = 0; i < fac.size(); i++) {
			if (mask >> i & 1) a *= fac[i];
			else b *= fac[i];
		}
		if (max(a, b) < max(aa, bb)) aa = a, bb = b;
	}
	cout << aa << " " << bb << endl;
	return 0;
}