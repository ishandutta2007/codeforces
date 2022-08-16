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

		int min_ans = (int) s.length();
		for (int i = 0; i < (int) s.length(); i++) {
			for (int j = i + 1; j < (int) s.length(); j++) {
				if (s[j] == '5') {
					if (s[i] == '2' || s[i] == '7') {
						min_ans = min(min_ans, j - i - 1 + (int) s.length() - j - 1);
					}
				} else if (s[j] == '0') {
					if (s[i] == '0' || s[i] == '5') {
						min_ans = min(min_ans, j - i - 1 + (int) s.length() - j - 1);
					}
				}
			}
		}

		cout << min_ans << '\n';
	}
	return 0;
}