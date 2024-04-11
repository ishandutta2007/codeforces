#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	if (n == 1) {cout << 0; return 0;}
	int x = 0, y = 0;
	string s;
	cin >> s;
	if (s[0] == 'U') y++;
	else x++;
	bool up = 0, down = 0;
	if (s[0] == 'U') up = 1;
	else down = 1;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'U') {y++;}
		else {x++;}
		if (up && x > y) {ans++; up = 0; down = 1; continue;}
		if (down && y > x) {ans++; up = 1; down = 0; continue;}
	}
	cout << ans;
	
	return 0;
}