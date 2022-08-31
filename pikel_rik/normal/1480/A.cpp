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

		for (int i = 0; i < int(s.length()); i++) {
			if (i % 2 == 0) {
				s[i] = (s[i] == 'a' ? 'b' : 'a');
			} else {
				s[i] = (s[i] == 'z' ? 'y' : 'z');
			}
		}
		cout << s << '\n';
	}
	return 0;
}