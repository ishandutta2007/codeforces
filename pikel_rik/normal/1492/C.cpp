#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s >> t;

	vector<int> suf(m, -1);
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
		if (s[i] == t[j]) {
			suf[j--] = i;
		}
	}

	int ans = 1;
	for (int i = 0, j = 0; i < n && j < m - 1; i++) {
		if (s[i] == t[j]) {
			ans = max(ans, suf[++j] - i);
		}
	}
	cout << ans << '\n';
	return 0;
}