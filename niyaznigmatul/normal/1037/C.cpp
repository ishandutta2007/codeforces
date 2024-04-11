#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i < n; ) {
		if (s[i] == t[i]) {
			i++;
			continue;
		}
		int j = i;
		while (j < n && s[j] != t[j]) ++j;
		int cur = j - i;
		while (i < j) {
			if (i + 1 < j && s[i] != s[i + 1]) {
				cur--;
				i++;
			}
			i++;
		}
		ans += cur;
	}
	cout << ans << endl;
}