#include <iostream>

using namespace std;

int main() {
	string x, y;
	cin >> x;
	for (int i = 1; i <= 5; i++) {
		cin >> y;
		if (x[0] == y[0] || x[1] == y[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}