#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i + 2 < n; i++) {
		cnt += s.substr(i, 3) == "abc";
	}

	while (q--) {
		int i; char c;
		cin >> i >> c, --i;

		for (int j = i - 2; j <= i; j++) {
			if (j >= 0 && j + 2 < n && s.substr(j, 3) == "abc") {
				cnt -= 1;
			}
		}

		s[i] = c;

		for (int j = i - 2; j <= i; j++) {
			if (j >= 0 && j + 2 < n && s.substr(j, 3) == "abc") {
				cnt += 1;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}