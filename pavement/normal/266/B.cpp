#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	string s;
	cin >> n >> t >> s;
	while (t--) {
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == 'B' && s[i + 1] == 'G') {
				s[i] = 'G';
				s[i + 1] = 'B';
				i++;
			}
		}
	}
	for (char c : s) cout << c;
}