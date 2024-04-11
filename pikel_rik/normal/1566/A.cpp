#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, s;
		cin >> n >> s;

		int median = n / 2 + 1;
		cout << s / median << '\n';
	}
	return 0;
}