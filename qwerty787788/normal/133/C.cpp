#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
string a;
long long answ = 0, umn = 1;
//
string dv(int x) {
	string ans = "";
	umn = 128;
	while (umn != 0) {
		if (x >= umn) {
			x-=umn;
			ans += '1';
		} else ans += '0';
		umn /= 2;
	}
	return ans;
};
//
int toint(string s) {
	umn = 128;
	int ans = 0;
	int i = 0;
	while (umn != 0) {
		if (s[i] == '1') ans += umn;
		i++;
		umn /= 2;
	}
	return ans;
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	string s = "", s1="";

	while (cin >> s1) {
		s+= s1+" ";
	}
	s = s.substr(0, s.size() - 1);
	int last = 0;
	//
	for (int i = 0; i < s.size(); i++) {
		string s1 = dv((int)s[i]);
		reverse(s1.begin(), s1.end());
		int x = toint(s1);
		cout << (last - x + 256) % 256 << endl;

		last = x;
	}
	//
}