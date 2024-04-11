#include <bits/stdc++.h>
using namespace std;

long long f[256][256];
long long cnt[256];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	for (char c: s) {
		for (char j = 'a'; j <= 'z'; j++) {
			f[c][j] += cnt[j];
		}
		cnt[c]++;
	}

	long long ans = 0;
	for (int i = 'a'; i <= 'z'; i++) {
		ans = max(ans, cnt[i]);
		for (int j = 'a'; j <= 'z'; j++) {
			ans = max(ans, f[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}