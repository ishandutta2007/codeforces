#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	int a = 0;
	for (char c: s) a += c == '0';
	int b = size(s) - a;
	if (a == b) {
		cout << a-1 << '\n';
	} else {
		cout << min(a,b) << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}