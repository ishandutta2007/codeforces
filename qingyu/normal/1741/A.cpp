#include <bits/stdc++.h>

using namespace std;

int get_value(string s) {
	if (s == "M")
		return 0;
	if (s[(int)(s.length())-1] == 'S')
		return -1 * (int)(s.length());
	return s.length();
}

void solve() {
	string s, t;
	cin >> s >> t;
	if (s == t) {
		cout << "=" << "\n";
		return;
	}
	if (get_value(s) > get_value(t)) {
		cout << ">\n";
	}
	else {
		cout << "<\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}