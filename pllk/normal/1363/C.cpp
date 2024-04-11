#include <iostream>

using namespace std;

int main() {
	string a = "Ayush";
	string b = "Ashish";
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int d = 0;
		for (int i = 1; i <= n-1; i++) {
			int a, b;
			cin >> a >> b;
			if (a == x || b == x) d++;
		}
		if (n == 1 || n == 2 || d == 1) {
			cout << a << "\n";
		} else if ((n-3)%2 == 0) {
			cout << b << "\n";
		} else {
			cout << a << "\n";
		}
	}
}