#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			if (i <= n/2-1 || i == n) {
				a += (1<<i);
			} else {
				b += (1<<i);
			}
		}
		cout << abs(a-b) << "\n";
	}
}