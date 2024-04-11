#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	
	int t;

	cin.sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;

	while (t--) {
		long long p, q, b;
		cin >> p >> q >> b;

		long long qq = q / __gcd(p, q);
		while (true) {
			long long g = __gcd(qq, b);
			if (g == 1) break;
			b = g;
			qq /= g;
		}
		cout << (qq == 1 ? "Finite" : "Infinite") << "\n";
	}
	return 0;
}