#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	for (int i = 1; i < s.size()-1; i++) {
		if (s[i] == 'A') {
			if (s[i-1] == 'B' && s[i+1] == 'C' || s[i-1] == 'C' && s[i+1] == 'B') {cout << "YES"; return 0;}
		}
		if (s[i] == 'B') {
			if (s[i-1] == 'A' && s[i+1] == 'C' || s[i-1] == 'C' && s[i+1] == 'A') {cout << "YES"; return 0;}
		}
		if (s[i] == 'C') {
			if (s[i-1] == 'B' && s[i+1] == 'A' || s[i-1] == 'A' && s[i+1] == 'B') {cout << "YES"; return 0;}
		}
	}
	cout << "NO";
	
	return 0;
}