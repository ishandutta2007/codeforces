#include <bits/stdc++.h>
using namespace std;

const int MOD = 20000;

int main() {
	int n;
	cin >> n;
	
	bool valid = true;
	int pos = 0;
	
	while (n--) {
		int dir;
		string s;
		cin >> dir >> s;

		if (pos == 0 && s[0] != 'S' || pos == 20000 && s[0] != 'N')
			valid = false;
		
		if (s[0] == 'S') {
			pos += dir;
			if (pos > 20000)
				valid = false;
		}
			
		if (s[0] == 'N') {
			pos -= dir;
			if (pos < 0)
				valid = false;
		}
	}
	
	valid &= (pos == 0);
	
	cout << (valid ? "YES\n" : "NO\n");
	
	return 0;
}