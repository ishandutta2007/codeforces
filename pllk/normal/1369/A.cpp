#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n%4 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}