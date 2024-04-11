#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
	cin >> s;
	cin >> n;
	if (((s=="front") && (n == 1)) || ((s=="back") && (n == 2))) {
		cout << "L" << endl;
	} else {
		cout << "R" << endl;
	}
	//
	return 0;
}