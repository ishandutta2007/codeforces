#include <bits/stdc++.h>
using namespace std;

bool hasDistinctDigits(string n) {
	unordered_set<char> s;
	for (char c : n) s.insert(c);
	return s.size() == n.length();
}

int main() {
	int y;
	cin >> y;
	y++;
	while (!hasDistinctDigits(to_string(y))) y++;
	cout << y;
}