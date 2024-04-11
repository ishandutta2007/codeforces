#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	int fo = 0, se = 0;
	for (int i = 0; i < s.size(); i++) {
	      fo += (s[i] == '4');
	      se += (s[i] == '7');
	}
	if (se > fo) {cout << 7; return 0;}
	else if (fo) {cout << 4; return 0;}
	else {cout << -1; return 0;}
	
	return 0;
}