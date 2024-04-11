#include <bits/stdc++.h>
using namespace std;

int main() {

	int ans = 0;
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
	      if (s[i] == 'L') {x++;}
	      if (s[i] == 'U') {y++;}
	}
	for (int i = 0; i < n; i++) {
	      if (s[i] == 'D' && y) {ans += 2; y--;}
	      if (s[i] == 'R' && x) {ans += 2; x--;}
	}
	cout << ans;
	
	return 0;
}