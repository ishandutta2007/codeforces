#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	if (s.size() <= 2) {
		cout << "YES";
		return 0;
	}
	int a = s[0] - 'A', b = s[1] - 'A';
	for (int i = 2; i < s.size(); ++i) {
		int c = s[i] - 'A';
		if ((a + b) % 26 != c) {
			cout << "NO";
			return 0;
		}
		a = b, b = c;
	}
	cout << "YES";
	return 0;
}