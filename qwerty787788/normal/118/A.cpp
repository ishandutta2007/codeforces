#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
//#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
int n, m;
string s;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] != 'a') && (s[i] != 'o') && (s[i] != 'y') && (s[i] != 'e') && (s[i] != 'u') && (s[i] != 'i')) cout << "." << s[i];
	}
	cout << endl;
	
	return 0;
}