#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		int c = 0;
		bool ok = true;
		while (n != 1) {
			c++;
			if (n%3 != 0) {
				ok = false;
				break;
			}
			if (n%6 == 0) {
				n /= 6;
			} else {
				n *= 2;
			}
		}
		if (ok) cout << c << "\n";
		else cout << "-1\n";
	}
}