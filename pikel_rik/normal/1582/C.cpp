#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto is_palindrome = [](const string &s) -> bool {
		for (int i = 0; i < (int) s.length(); i++) {
			if (*(s.begin() + i) != *(s.rbegin() + i)) {
				return false;
			}
		}
		return true;
	};

	while (t--) {
		int n;
		cin >> n;

		string s, ss;
		cin >> s;

		int ans = n + 1;
		for (char c = 'a'; c <= 'z'; c++) {
			ss.clear();
			for (char ch : s) {
				if (c != ch) {
					ss += ch;
				}
			}
			if (is_palindrome(ss)) {
				int cur = (int) s.length() - (int) ss.length();

				int not_c_i = 0, not_c_j = 0;
				for (int i = 0, j = n - 1; i <= j; i++) {
					if (s[i] == c) {
						while (i < j && not_c_j < not_c_i) {
							not_c_j += s[j] != c;
							j -= 1;
						}
						if (i < j && not_c_j == not_c_i && s[j] == c) {
							cur -= 2;
							j -= 1;
						} else if (i == j && not_c_j == not_c_i) {
							cur -= 1;
							j -= 1;
						}
					} else {
						not_c_i += 1;
					}
				}
				ans = min(ans, cur);
			}
		}

		cout << (ans == n + 1 ? -1 : ans) << '\n';
	}
	return 0;
}