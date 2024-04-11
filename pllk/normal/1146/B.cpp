#include <iostream>

using namespace std;

void fail() {
	cout << ":(\n";
	exit(0);
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int a = 0;
	int x = 0;
	for (auto c : s) {
		if (c == 'a') a++;
		if (c != 'a') x++;
	}
	if (x%2 == 1) fail();
	x /= 2;
	string u;
	for (auto c : s) {
		if (c == 'a') {
			u += c;
			a--;
		} else {
			if (x) {
				u += c;
				x--;
			}
		}
	}
	if (a != 0) fail();
	string w = u;
	for (auto c : u) if (c != 'a') w += c;
	if (w != s) fail();
	cout << u << "\n";
}