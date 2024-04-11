#include <iostream>

using namespace std;

int a, b, c;

int main() {
	cin >> a >> b >> c;
	for (int x = 100; x >= 1; x--) {
		if (x <= a && x+1 <= b && x+2 <= c) {
			cout << x+x+1+x+2 << "\n";
			return 0;
		}
	}
}