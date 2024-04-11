#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a, b;

void solve() {
	cin >> a >> b;
	if (a % b == 0)
		cout << 0 << endl;
	else
		cout << b - a % b << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}