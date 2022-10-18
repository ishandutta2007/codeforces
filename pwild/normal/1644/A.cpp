#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	string s;
	cin >> s;
	bool res = true;
	for (char c: "RGB") {
		char d = tolower(c);
		int i = 0, j = 0;
		while (s[i] != d) i++;
		while (s[j] != c) j++;
		if (i > j) res = false;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}