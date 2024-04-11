#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		while (!s.empty() && (s.back() - '0') % 2 == 0) {
			s.pop_back();
		}

		int c = 0;
		for (auto &ch : s) {
			c += (ch - '0') % 2 != 0;
		}

		if (c < 2) {
			cout << "-1\n";
			continue;
		}

		if (c % 2 != 0) {
			for (int i = 0; i < s.length(); i++) {
				if ((s[i] - '0') % 2 != 0) {
					s.erase(s.begin() + i);
					break;
				}
			}
			while (s.front() == '0') {
				s.erase(s.begin());
			}
		}
		cout << s << '\n';
	}
	return 0;
}