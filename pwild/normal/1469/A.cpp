#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
	int n = s.size();
	if (n%2 == 1) return false;
	if (s[0] == ')' || s[n-1] == '(') return false;
	return true;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		cout << (solve(s) ? "YES" : "NO") << endl;
	}
}