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

		auto mn = min_element(s.begin(), s.end());
		cout << *mn << ' ';

		s.erase(mn);
		cout << s << '\n';
	}
	return 0;
}