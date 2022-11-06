#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, a = "hello";
	int y = 0;
	char t = a[0];
	cin >> s;
	for (char c : s) {
		if (c == t) {
			y++;
			t = a[min(y, 4)];
		}
	}
	if (y >= 5) cout << "YES";
	else cout << "NO";
}