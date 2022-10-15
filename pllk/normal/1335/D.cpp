#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 9; i++) {
			string s;
			cin >> s;
			for (auto c : s) {
				if (c == '1') cout << '2';
				else cout << c;
			}
			cout << "\n";
		}
	}
}