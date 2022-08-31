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

		int n = (int) s.length(), c = count(s.begin(), s.end(), '1');
		if (c == n) {
			cout << 0 << '\n';
		} else {
			int first = find(s.begin(), s.end(), '0') - s.begin();
			int last = find(s.rbegin(), s.rend(), '0') - s.rbegin();
			last = n - last - 1;

			if (count(s.begin() + first, s.begin() + last + 1, '1') > 0) {
				cout << 2 << '\n';
			} else {
				cout << 1 << '\n';
			}
		}
	}
	return 0;
}