#include <bits/stdc++.h>
using namespace std;

int main() {
	set<char> chars;
	string s;
	cin >> s;
	for (char c : s) chars.insert(c);
	chars.size() % 2 == 0 ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
}