#include <bits/stdc++.h>
using namespace std;

int main() {
	char c, d;
	unordered_set<char> s;
	cin >> c;
	while (d != '}') {
		cin >> c;
		if (c == '}') break;
		s.insert(c);
		cin >> d;
	}
	cout << s.size();
}