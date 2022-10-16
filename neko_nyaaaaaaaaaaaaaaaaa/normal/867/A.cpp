#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int fs = 0, sf = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'S' && s[i-1] == 'F') {fs++;}
		if (s[i] == 'F' && s[i-1] == 'S') {sf++;}
	}
	if (sf > fs) {cout << "YES";}
	else cout << "NO";
	
	return 0;
}