#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case) {
		string s;
		cin >> s;
		int n = s.length();
		vector<int> cnt(10), f(n + 1, 0x3f3f3f3f);
		for (int i = n - 1; i >= 0; --i) {
			int x = s[i] - '0';
			f[i] = min(f[i + 1], x);
		}	
		string t = "";
		auto go = [&](int c) {
			if (cnt[c] > 0) {
				t += string(cnt[c], c + '0');
				cnt[c] = 0;
			}
		};
		for (int i = 0; i < n; ++i) {
			for (int c = 0; c < f[i]; ++c) {
				go(c);
			}
			int x = s[i] - '0';
			if (x == f[i]) {
				t += '0' + x;
			}
			else {
				if (x < 9) ++x;
				++cnt[x];
			}
		}
		for (int c = 0; c <= 9; ++c)
			go(c);
		cout << t << '\n';
	}
}