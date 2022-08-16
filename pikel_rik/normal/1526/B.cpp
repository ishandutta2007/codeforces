#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	vector<bool> possible(1110 + 1);
	possible[0] = true;

	for (int i = 1; i <= 1110; i++) {
		for (auto x : {11, 111, 1111}) {
			if (i >= x && possible[i - x]) {
				possible[i] = true;
			}
		}
	}

	while (t--) {
		int x;
		cin >> x;

		cout << (x >= 1110 || possible[x] ? "YES" : "NO") << '\n';
	}
	return 0;
}