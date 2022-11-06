#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); };

int main() {
	bool s = true;
	int a, b, n;
	cin >> a >> b >> n;
	while (true) {
		if (n - gcd((s ? a : b), n) < 0) {
			cout << s;
			break;
		}
		else n -= gcd((s ? a : b), n);
		s = !s;
	}
}