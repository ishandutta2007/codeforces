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
		int half = n / 2;

		if (n == 1) {
			s = "a";
		} else if (n % 2 == 0) {
			s += string(half - 1, 'a');
			s += 'b';
			s += string(half, 'a');
		} else {
			s += string(half - 1, 'a');
			s += 'b', s += 'c';
			s += string(half, 'a');
		}
		cout << s << '\n';
	}
	return 0;
}