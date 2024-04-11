#include <bits/stdc++.h>

/**
 * Author: Niyaz Nigmatullin
 */

using namespace std;

void solve() {
	string s;
	cin >> s;
	vector<int> a;
	for (int i = 0; i < (int) s.size(); ) {
		if (s[i] == '0') {
			i++;
			continue;
		}
		int j = i;
		while (j < (int) s.size() && s[i] == s[j]) ++j;
		a.push_back(j - i);
		i = j;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < (int) a.size(); i += 2) {
		ans += a[i];
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}