#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	if (s[0] == 'D') for (char &c: s) c ^= 'R' ^ 'D';

	int a = 0, b = 0, k = 0;
	for (char c: s) a += c == 'R';
	for (char c: s) b += c == 'D';
	while (k < ssize(s) && s[k] == 'R') k++;

	i64 res = i64(n) * n;
	if (b == 0) {
		res = n;
	} else {
		res -= i64(k) * (n-1-b) + i64(a) * b;
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}