#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			if (a%2 == 0) c0++;
			else c1++;
		}
		if (c1 == 0) {
			cout << "NO\n";
			continue;
		}
		c1--;
		x--;
		while (x >= 2 && c1 >= 2) {
			x -= 2; c1 -= 2;
		}
		while (x && c0) {
			x--; c0--;
		}
		if (x == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}