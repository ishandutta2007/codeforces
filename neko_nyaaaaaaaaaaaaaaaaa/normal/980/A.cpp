#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	int o = 0, e = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'o') {
			o++;
		} else {
			e++;
		}
	}
	
	if (o == 0) {cout << "YES"; return 0;}
	
	if (e % o == 0) {cout << "YES"; return 0;}
	cout << "NO";
	
	return 0;
}