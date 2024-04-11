#include <iostream>
#include <string>
using namespace std;

/*
Time Complexity: Pretty bad but fits to the problem
also really simple to implement
O(|s| + |s| ^ 2 + |s| ^ 3)
*/



int main() {
	int n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		n = s[i] - '0';
		if (n % 8 == 0) {
			cout << "YES" << '\n' << n << endl;
			return 0;
		}
	}
	for (int i = 0; i < s.size(); i++) for (int j = i + 1; j < s.size(); j++) {
		n = 10 * s[i] + s[j] - 11 * '0';
		if (n % 8 == 0) {
			cout << "YES" << '\n' << n << endl;
			return 0;
		}
	}
	for (int i = 0; i < s.size(); i++) for (int j = i + 1; j < s.size(); j++) for (int k = j + 1; k < s.size(); k++) {
		n = 100 * s[i] + 10 * s[j] + s[k] - 111 * '0';
		if (n % 8 == 0) {
			cout << "YES" << '\n' << n << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}