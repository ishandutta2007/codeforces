#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int l = 0, u = 0;
	cin >> s;
	for (char c : s) {
		if (islower(c)) l++;
		else u++;
	}
	if (u > l) for (char c : s) cout << char(toupper(c));
	else for (char c : s) cout << char(tolower(c));
}