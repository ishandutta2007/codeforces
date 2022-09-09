#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long n;

string s1 = "abcdefghijklmnopqrstuvwxyz";
string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string s;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		if (s2.find(s[i]) != -1) sum++;
	if ((sum == s.size()) || ((sum == s.size() - 1) && (s1.find(s[0]) != -1))) {
		for (int i = 0; i < s.size(); i++)
			if (s1.find(s[i]) != -1) cout << s2[s1.find(s[i])]; else
									 cout << s1[s2.find(s[i])];
	} else {
		cout << s;
	}
	cout << endl;
	//
	return 0;
}