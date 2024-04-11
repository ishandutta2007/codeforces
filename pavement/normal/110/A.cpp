#include <bits/stdc++.h>
using namespace std;

int main() {
	long long d = 0;
	string n;
	cin >> n;
	for (char c : n) if (c == '4' || c == '7') d++;
	if (d == 0) {
		cout << "NO";
		return 0;
	}
	for (char c : to_string(d)) {
		if (c != '4' && c != '7') {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}