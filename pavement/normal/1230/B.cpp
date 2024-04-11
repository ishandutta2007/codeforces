#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	if (n == 1 && k >= 1) {
		cout << "0\n";
		return 0;
	}
	if (k >= 1 && s[0] > '1') s[0] = '1', k--;
	for (int i = 1; i < n; i++)
		if (k && s[i] > '0') s[i] = '0', k--;
	cout << s << '\n';
}