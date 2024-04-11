#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();

	long long ans = 0;
	for (int l = 0; l < n; l++) {
		int r = n;
		for (int x = 0; x <= 20; x++) {
			for (int k = 1; k <= 20; k++) {
				if (l+x < n && l+x+k < n && l+x+k+k < n) {
					if (s[l+x] == s[l+x+k] && s[l+x] == s[l+x+k+k]) {
						r = min(r, l+x+k+k);
					}
				}
			}
		}

		ans += max(0, n-r);
	}
	cout << ans;

	return 0;
}