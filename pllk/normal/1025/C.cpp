#include <iostream>

using namespace std;

string s;
int n;

int main() {
	cin >> s;
	n = s.size();
	int u = 1;
	int a = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) u++;
		else u = 1;
		if (u > a) a = u;
	}
	if (a == n) {
		cout << a << "\n";
		return 0;
	}
	int b = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) b++;
		else break;
	}
	if (s[0] != s[n-1]) {
		b++;
		for (int i = n-2; i >= 0; i--) {
			if (s[i] != s[i+1]) b++;
			else break;
		}
	}
	cout << max(a,b) << "\n";
}