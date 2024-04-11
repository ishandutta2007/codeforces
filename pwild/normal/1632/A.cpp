#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n; cin >> n;
	string s; cin >> s;
	if (n >= 3) return false;
	if (n == 2 && s[0] == s[1]) return false;
	return true;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}