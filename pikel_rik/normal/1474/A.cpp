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

		string a, b;
		cin >> b;

		int last = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] - '0' + 1 == last) {
				a += '0';
				last = b[i] - '0';
			} else {
				a += '1';
				last = b[i] - '0' + 1;
			}
		}
		cout << a << '\n';
	}
	return 0;
}