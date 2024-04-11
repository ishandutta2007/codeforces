#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		int n = (int) s.length();

		vector<int> freq(26);
		for (auto &ch : s) {
			freq[ch - 'a'] += 1;
		}

		int mn = -1;
		for (int i = 0; i < 26; i++) {
			if (freq[i] > 0) {
				if (mn == -1 || freq[i] < freq[mn]) {
					mn = i;
				}
			}
		}

		if (freq[mn] == 1) {
			int j = find(s.begin(), s.end(), 'a' + mn) - s.begin();
			swap(s[0], s[j]);
			sort(s.begin() + 1, s.end());
		} else if (freq[mn] < n) {
			for (int j = 0; j < 26; j++) {
				if (freq[j] > 0) {
					mn = j;
					break;
				}
			}
			int b = -1;
			if (freq[mn] > n / 2 + 1) {
				for (int j = mn + 1; j < 26; j++) {
					if (freq[j] > 0) {
						b = j;
						break;
					}
				}
			}

			string t;
			t += 'a' + mn;

			if (b == -1) {
				t += 'a' + mn, freq[mn] -= 2;
				sort(s.begin(), s.end());
				auto [lb, ub] = equal_range(s.begin(), s.end(), 'a' + mn);
				s.erase(lb, ub);
				for (int i = 0, j = 0; i < n - 2; i++) {
					if (freq[mn] == 0 || t.size() % 2 == 0) {
						t += s[j];
						j += 1;
					} else {
						t += 'a' + mn;
						freq[mn] -= 1;
					}
				}
			} else {
				t += 'a' + b;
				freq[mn] -= 1, freq[b] -= 1;

				int found = -1;
				for (int j = b + 1; j < 26; j++) {
					if (freq[j] > 0) {
						found = j;
						break;
					}
				}

				if (found == -1) {
					for (int i = 0; i < freq[b]; i++) {
						t += 'a' + b;
					}
					for (int i = 0; i < freq[mn]; i++) {
						t += 'a' + mn;
					}
				} else {
					for (int i = 0; i < freq[mn]; i++) {
						t += 'a' + mn;
					}
					t += 'a' + found, freq[found] -= 1;
					for (int i = mn + 1; i < 26; i++) {
						for (int j = 0; j < freq[i]; j++) {
							t += 'a' + i;
						}
					}
				}
			}
			s.swap(t);
		}
		cout << s << '\n';
	}
	return 0;
}