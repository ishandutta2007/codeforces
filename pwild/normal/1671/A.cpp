#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		bool ok = true;
		for (int i = 0; i < ssize(s); i++) {
			bool left = i == 0 || s[i] != s[i-1];
			bool right = i+1 == ssize(s) || s[i+1] != s[i];
			if (left && right) ok = false;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}