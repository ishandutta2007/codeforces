#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
string a;
long long answ = 0, umn = 1;
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
	//
	for (int i = 0; i <s.size(); i++) {
		if (s[i] == '>') a += "1000";
		if (s[i] == '<') a += "1001";
		if (s[i] == '+') a += "1010";
		if (s[i] == '-') a += "1011";
		if (s[i] == '.') a += "1100";
		if (s[i] == ',') a += "1101";
		if (s[i] == '[') a += "1110";
		if (s[i] == ']') a += "1111";
	}
	//
	for (int i = a.size() - 1; i >= 0; i--) {
		answ = (answ + (a[i] - '0') * umn) % (1000003);
		umn *= 2;
		umn %= 1000003;
	}
	cout << answ;
	//
}