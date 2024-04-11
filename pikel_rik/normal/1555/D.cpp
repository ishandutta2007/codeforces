#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	vector<int> abc = {0, 1, 2};
	vector<vector<int>> perms;

	do {
		perms.push_back(abc);
	} while (next_permutation(abc.begin(), abc.end()));

	array<vector<array<int, 3>>, 3> pref;
	for (int i = 0; i < 3; i++) {
		array<int, 3> cnt = {0};
		for (int j = i; j < n; j += 3) {
			cnt[s[j] - 'a'] += 1;
			pref[i].push_back(cnt);
		}
	}

	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r, --l, --r;

		if (l == r) {
			cout << 0 << '\n';
			continue;
		} else if (l + 1 == r) {
			cout << (s[l] == s[r]) << '\n';
			continue;
		}

		int cost = r - l + 1;
		for (auto &perm : perms) {
			int now = 0;
			array<int, 3> first, last;
			for (int j = 0; j < 3; j++) {
				first[(l + j) % 3] = (l + j) / 3;
				last[(r - j) % 3] = (r - j) / 3;
			}
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k != perm[j]) {
						now += pref[j][last[j]][k];
						if (first[j] > 0) {
							now -= pref[j][first[j] - 1][k];
						}
					}
				}
			}
			cost = min(cost, now);
		}
		cout << cost << '\n';
	}
	return 0;
}