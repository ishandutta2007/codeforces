/** If you managed to hack this code, 
 * I would be grateful if you would message me the hack test
 * and, if not too much to ask, along with where I got wrong 
 * Thanks in advance :D */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	bool vow = 0;
	for (int i = 0; i < s.size(); i++) {
		if (vow == 0) {
			if (s[i] == 'a' || s[i] == 'y' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				vow = 1;
				cout << s[i];
			} else {cout << s[i];}
		} else {
			if (s[i] == 'a' || s[i] == 'y' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				continue;
			} else {
				cout << s[i];
				vow = 0;
			}
		}
	}
	
	return 0;
}