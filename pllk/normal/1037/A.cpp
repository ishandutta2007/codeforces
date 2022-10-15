#include <iostream>

using namespace std;

int n;
int c;

int main() {
	cin >> n;
	int u = 1;
	while (u <= n) {
		n -= u;
		c++;
		u *= 2;
	}
	if (n != 0) c++;
	cout << c << "\n";
}