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

		int n = (int) s.length();

		vector<int> segments = {1};
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				segments.back() += 1;
			} else {
				segments.push_back(1);
			}
		}

		if (segments.size() % 2 == 0) {
			s[0] = 'a' + 'b' - s[0];
		}
		cout << s << '\n';
	}
	return 0;
}