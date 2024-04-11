#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//
int n;
string s;
int s4, s7;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '4') s4++;
		if (s[i] == '7') s7++;
	}
	if ((s4 == 0) && (s7 == 0)) {
		cout << "-1";
	} else {
		if (s7 > s4) {
			cout << 7;
		} else {
			cout << 4;
		}
	}
	//
	return 0;
}