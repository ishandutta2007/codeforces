#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
//
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	string s = "", s1="";

	while (cin >> s1) {
		s+= s1;
	}
	if (s.find("H") != -1 || s.find("Q") != -1 || s.find("9") != -1) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}