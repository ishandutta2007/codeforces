#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'H' || c == 'Q' || c == '9') {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}