#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, int> m;
	string a, b, c;
	cin >> a >> b >> c;
	for (char e : a) m[e]++;
	for (char e : b) m[e]++;
	for (char e : c) m[e]--;
	for (auto i : m) {
		if (i.second != 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}