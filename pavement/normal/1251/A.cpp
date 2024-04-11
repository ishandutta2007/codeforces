#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		char p = 0;
		int co = 0;
		set<char> se;
		for (char c : s) {
			if (p == 0) {
				co = 1;
			} else if (p == c) {
				co++;
			} else {
				if (co % 2 != 0) se.insert(p);
				co = 1;
			}
			p = c;
		}
		if (co % 2 != 0) se.insert(p);
		for (char c : se) printf("%c", c);
		printf("\n");
	}
}