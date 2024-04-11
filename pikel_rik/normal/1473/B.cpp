#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		string s, t;
		cin >> s >> t;

		int lcm_len = s.length() / __gcd(s.length(), t.length()) * t.length();

		string lcm;
		for (int i = 0; i < lcm_len / s.length(); i++) lcm += s;

		bool no_lcm = false;
		for (int i = 0, j = 0; i < lcm.length(); i++, j = (j + 1) % t.length()) {
			no_lcm |= t[j] != lcm[i];
		}

		if (no_lcm) {
			cout << "-1\n";
		} else cout << lcm << '\n';
	}
	return 0;
}