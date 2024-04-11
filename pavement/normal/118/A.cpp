#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		c = tolower(c);
		if (c != 'a' && c != 'o' && c != 'y' && c != 'e' && c != 'u' && c != 'i') cout << "." << c;
	}
}