#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	long long grp = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '0') {
			++grp;
			if (i > 0 && s[i - 1] == s[i]) --grp;
		}
	}
	if (!grp) {
		cout << 0 << "\n";
	}
	else {
		cout << (grp - 1) * min(x, y) + y << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}