#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0, w = 0;
	vector<int> ret;
	for (int i = 0; i < 2 * n; i += 2) {
		if (s[i] != s[i + 1]) {
			c = !c;
			ret.push_back(i + 1);
			if (s[i] - '0' != w)
				++ret.back();
			w = !w;
		}
	}
	if (c) {
		cout << "-1\n";
	}
	else {
		cout << ret.size() << '\n';
		for (int i = 0; i < ret.size(); ++i)
			cout << ret[i] << " \n"[i + 1 == ret.size()];
		for (int i = 1; i <= 2 * n; i += 2)
			cout << i << " \n"[i + 1 == 2 * n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}