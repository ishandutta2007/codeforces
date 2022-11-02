#include <iostream>
using namespace std;
long long gcd(long long, long long);
int main() {
	long long l, r, i, j, k;
	ios::sync_with_stdio(false);
	cin >> l >> r;
	for(i = l; i <= r; i++) {
		for(j = i + 1; j <= r; j++) {
			if(gcd(i, j) == 1LL) {
				for(k = j + 1; k <= r; k++) {
					if(gcd(j, k) == 1LL && gcd(k, i) != 1LL) {
						cout << i << " " << j << " " << k << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
long long gcd(long long a, long long b) {
	return a % b == 0 ? b : gcd(b, a % b);
}