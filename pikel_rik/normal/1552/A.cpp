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

		string temp = s;
		sort(temp.begin(), temp.end());

		int mismatch = 0;
		for (int i = 0; i < n; i++) {
			mismatch += s[i] != temp[i];
		}
		cout << mismatch << '\n';
	}
	return 0;
}