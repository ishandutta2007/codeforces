#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	map<char, int> mp;
	mp['A'] = 0, mp['N'] = 1, mp['O'] = 2, mp['T'] = 3;

	vector<char> inv_mp = {'A', 'N', 'O', 'T'};

	while (t--) {
		string s;
		cin >> s;

		for (auto &ch : s) {
			ch = mp[ch];
		}

		int n = s.length();

		array<int, 4> cnt = {};
		vector<vector<long long>> inv(4, vector<long long>(4));

		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 4; k++) {
				if (k != s[i]) {
					inv[s[i]][k] += cnt[k];
				}
			}
			cnt[s[i]] += 1;
		}

		vector<int> ord(4);
		iota(ord.begin(), ord.end(), 0);

		long long mx = 0;
		do {
			long long cur = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = i + 1; j < 4; j++) {
					cur += inv[ord[i]][ord[j]];
				}
			}
			mx = max(mx, cur);
		} while (next_permutation(ord.begin(), ord.end()));

		string b;
		iota(ord.begin(), ord.end(), 0);

		do {
			long long cur = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = i + 1; j < 4; j++) {
					cur += inv[ord[i]][ord[j]];
				}
			}
			if (mx == cur) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < cnt[ord[i]]; j++) {
						b += inv_mp[ord[i]];
					}
				}
				break;
			}
		} while (next_permutation(ord.begin(), ord.end()));
		cout << b << '\n';
	}
	return 0;
}