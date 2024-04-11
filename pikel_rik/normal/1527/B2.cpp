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

		int init = 0;
		for (int i = 0; i < n - i - 1; i++) {
			init += s[i] != s[n - i - 1];
		}

		int c = n - count(s.begin(), s.end(), '1') - init;
		int score = 0;

		if (init == 0) {
			if (c % 2 != 0) {
				if (c == 1) {
					score -= 1;
				} else {
					score += 1;
				}
			} else {
				score -= 2;
			}
		} else {
			if (c % 2 != 0) {
				if (c > 1) {
					score = init + 1;
				} else {
					score = init - 1;
				}
			} else {
				score = init;
			}
		}

		if (score > 0)
			cout << "ALICE\n";
		else if (score < 0)
			cout << "BOB\n";
		else cout << "DRAW\n";
	}
	return 0;
}