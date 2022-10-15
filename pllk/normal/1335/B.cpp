#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 0; i < n; i++) {
			if (i%a < b-1) cout << (char)('a'+i%a+1);
			else cout << 'a';
		}
		cout << "\n";
	}
}