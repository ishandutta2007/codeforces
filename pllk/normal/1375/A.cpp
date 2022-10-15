#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			x = abs(x);
			if (i%2 == 1) x = -x;
			cout << x << " ";
		}
		cout << "\n";
	}
}