#include <bits/stdc++.h>

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	std::vector<int> a(n), cnt(4), p = {0, 1, 2, 3};
	long long c[4][4];
	memset(c, 0, sizeof c);
	auto trans = [&](int ch) {
		if (ch == 'A') return 0;
		if (ch == 'N') return 1;
		if (ch == 'T') return 2;
		return 3;
	};
	for (int i = 0; i < n; ++i)
		a[i] = trans(s[i]), ++cnt[a[i]];
	for (int k : {0, 1, 2, 3}) {
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			c[k][a[j]] += cur;
			if (k == a[j]) ++cur;
		}
	}
	long long ans = -1;
	std::vector<int> best;
	do {
		long long cur = c[p[0]][p[1]] + c[p[0]][p[2]] + c[p[0]][p[3]] + c[p[1]][p[2]] + c[p[1]][p[3]] + c[p[2]][p[3]];
		if (ans < cur) {
			ans = cur;
			best = p;
		}
	} while (std::next_permutation(p.begin(), p.end()));
	std::vector<char> tr = { 'A', 'N', 'T', 'O' };
	for (int i = 3; i >= 0; --i)
		for (int j = 0; j < cnt[best[i]]; ++j)
		   putchar(tr[best[i]]);
	putchar('\n');	
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t--) solve();
	return 0;
}