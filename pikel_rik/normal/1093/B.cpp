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

		if (count(s.begin(), s.end(), s.front()) == s.size()) {
			cout << "-1\n";
		} else {
			sort(s.begin(), s.end());
			cout << s << '\n';
		}
	}
	return 0;
}