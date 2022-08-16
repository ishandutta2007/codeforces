#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> pref(n);
	pref[0] = s[0] == '(' ? 1 : -1;

	for (int i = 1; i < n; i++) {
		pref[i] = (s[i] == '(' ? 1 : -1) + pref[i - 1];
	}

	if (pref.back() != 0) {
		return cout << "-1\n", 0;
	}

	int ans = 0, len = 0;
	for (int i = 0; i < n; i++) {
		if (pref[i] == 0 && len > 0) {
			ans += len + 1;
		}
		if (pref[i] < 0)
			len += 1;
		else len = 0;
	}
	cout << ans << '\n';
	return 0;
}