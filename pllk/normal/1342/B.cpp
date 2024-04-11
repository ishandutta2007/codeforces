#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int f = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s[0]) f = 1;
		}
		if (f == 0) {
			cout << s << "\n";
		} else {
			for (int i = 0; i < s.size(); i++) {
				cout << "01";
			}
			cout << "\n";
		}
	}
}