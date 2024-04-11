#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool ans = true;
int n, t, c = 20000;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> t >> s;
		if (s == "North") {
			c += t;
			if (c > 20000) ans = false;
		}
		else if (s == "South") {
			c -= t;
			if (c < 0) ans = false;
		}
		else if (c == 0 || c == 20000) ans = false;
	}
	if (!ans || c != 20000) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}