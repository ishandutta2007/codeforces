#include <iostream>
using namespace std;
int main() {
	long long t, n, x;
	cin >> t;
	while (t--) {
		cin >> n, x = n % 4;
		if (x == 0) cout << 4 * n + 1 << endl;
		if (x == 1) cout << 2 * n + 1 << endl;
		if (x == 2) cout << 4 * n + 1 << endl;
		if (x == 3) cout << n + 1 << endl;
	}
}