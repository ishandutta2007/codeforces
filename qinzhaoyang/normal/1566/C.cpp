#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T, f[100010];
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		int n, ans = 0; cin >> n;
		cin >> s1 >> s2;
		for (int i = 0; i < n; i++) f[i] = 0;
		for (int i = 0; i < n; i++) {
			if (s1[i] == '0' && s2[i] == '1' || s1[i] == '1' && s2[i] == '0')
				ans += 2;
			else if (s1[i] == '0' && s2[i] == '0') ans++;
			else {
				if (i != 0 && s1[i - 1] == '0' && s2[i - 1] == '0' && f[i - 1] == 0)
					ans++;
				else if (i != n - 1 && s1[i + 1] == '0' && s2[i + 1] == '0')
					ans++, f[i + 1] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}