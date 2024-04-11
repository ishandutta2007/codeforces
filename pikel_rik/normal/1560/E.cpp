#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string t;
		cin >> t;

		vector<int> freq(26);
		for (auto &ch : t) {
			freq[ch - 'a'] += 1;
		}

		int distinct = 26 - count(freq.begin(), freq.end(), 0);

		vector<int> used(26, -1), expected(26, 0), cnt(26, 0);

		string prev;
		for (int i = 0; i < distinct; i++) {
			int c = -1;
			for (int j = (int) t.length() - 1; j >= 0; j--) {
				if (used[t[j] - 'a'] == -1) {
					c = t[j] - 'a';
					break;
				}
			}
			if (c == -1 || freq[c] % (distinct - i) != 0) {
				break;
			}

			used[c] = i;
			expected[c] = freq[c] / (distinct - i);

			int hit = 0;
			bool bad = false;

			for (int j = (int) t.length() - 1, k = (int) prev.length() - 1; j >= 0; j--) {
				cnt[t[j] - 'a'] += 1;
				hit += cnt[t[j] - 'a'] == expected[t[j] - 'a'];
				if (k >= 0 && t[j] == prev[k]) {
					k -= 1;
				}
				if (hit == i + 1) {
					bad |= k != -1;
					prev = string(t.begin() + j, t.end());
					t.erase(t.begin() + j, t.end());
					break;
				}
			}

			for (int j = 0; j < 26; j++) {
				bad |= cnt[j] != expected[j];
			}
			if (bad) {
				used[c] = -1;
				break;
			} else {
				fill(cnt.begin(), cnt.end(), 0);
			}
		}

		string order(distinct, 0);
		for (int i = 0; i < 26; i++) {
			if (used[i] != -1) {
				order[distinct - used[i] - 1] = 'a' + i;
			}
		}

		if (count(order.begin(), order.end(), 0) > 0) {
			cout << "-1\n";
			continue;
		}

		cout << prev << ' ' << order << '\n';
	}
	return 0;
}