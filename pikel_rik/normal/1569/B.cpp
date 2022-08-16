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

		vector<string> win(n, string(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					win[i][j] = 'X';
				} else if (s[i] == '1' || s[j] == '1') {
					win[i][j] = '=';
				}
			}
		}

		vector<int> twos;
		for (int i = 0; i < n; i++) {
			if (s[i] == '2') {
				twos.push_back(i);
			}
		}

		if (twos.size() == 1 || twos.size() == 2) {
			cout << "NO\n";
			continue;
		}

		for (int i = 0; i < (int) twos.size(); i++) {
			int j = twos[i];
			int k = twos[(i + 1) % (int) twos.size()];
			win[j][k] = '+';
			win[k][j] = '-';
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (win[i][j] == 0) {
					win[i][j] = '=';
				}
			}
		}

		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << win[i] << '\n';
		}
	}
	return 0;
}