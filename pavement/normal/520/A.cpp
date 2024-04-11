#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<char> s;
	int n;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		s.insert(tolower(c));
	}
	s.size() == 26 ? cout << "YES" : cout << "NO";
}