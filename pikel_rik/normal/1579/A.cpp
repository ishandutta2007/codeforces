#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		array<int, 3> cnt = {};
		for (auto ch : s) {
			cnt[ch - 'A'] += 1;
		}

		cout << (cnt[1] == cnt[2] + cnt[0] ? "Yes" : "No") << '\n';
	}
	return 0;
}