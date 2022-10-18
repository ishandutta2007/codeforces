#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a; cin >> a;
	string b;
	set<char> s;
	for (char c: a) {
		if (s.count(c)) continue;
		b.push_back(c);
		s.insert(c);
	}

	bool res = true;
	for (int i = 0; i < ssize(a); i++) {
		if (a[i] != b[i%ssize(b)]) res = false;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}