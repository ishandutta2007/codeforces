#include <iostream>
using namespace std;

int n, m, b, c, mn = 2e9;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		if (c - b + 1 < mn) mn = c - b + 1;
	}
	cout << mn << endl;
	for (int i = 0; i < n; i++) cout << i % mn << ' '; cout << endl;
}