#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		if (n % k != 0) {
			cout << "-1\n";
			continue;
		}

		vector<int> cnt(26);
		for (auto ch : s) {
			cnt[ch - 'a'] += 1;
		}

		bool ok = true;
		for (int j = 0; j < 26; j++) {
			ok &= cnt[j] % k == 0;
		}

		if (ok) {
			cout << s << '\n';
			continue;
		}

		string ans;
		for (int i = n - 1; i >= 0 && ans.empty(); i--) {
			cnt[s[i] - 'a'] -= 1;
			int rem = n - i;
			for (int j = 0; j < 26; j++) {
				rem -= (k - cnt[j] % k) % k;
			}
			if (rem < 0) {
				continue;
			}
			int ch = -1;
			for (int j = 0; j < 26; j++) {
				if (j > s[i] - 'a' && ((k - cnt[j] % k) % k > 0 || rem > 0)) {
					ch = j;
					break;
				}
			}
			if (ch == -1) {
				continue;
			}
			ans = s.substr(0, i);
			for (int j = 0; j < 26; j++) {
				cnt[j] = (k - cnt[j] % k) % k;
			}
			ans += 'a' + ch;
			if (cnt[ch] > 0) {
				cnt[ch] -= 1;
			} else {
				cnt[ch] += k - 1;
				rem -= k;
			}
			cnt[0] += rem;
			for (int j = 0; j < 26; j++) {
				while (cnt[j]-- > 0) {
					ans += 'a' + j;
				}
			}
		}

		if (!ans.empty()) {
			cout << ans << '\n';
			continue;
		}

		if (s.front() == 'z') {
			cout << "-1\n";
			continue;
		}

		cnt.assign(26, 0);
		ans = s.front() + 1;
		cnt[s.front() + 1 - 'a'] += k - 1;
		cnt[0] += n - k;
		for (int j = 0; j < 26; j++) {
			while (cnt[j]-- > 0) {
				ans += 'a' + j;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}