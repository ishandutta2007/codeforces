#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') cnt++;
		}
		int l = 0;
		while (l < s.size() && s[l] == '0') l++;
		if (l == s.size()) {
			printf("0\n");
			continue;
		}
		int r = s.size() - 1;
		while (r >= 0 && s[r] == '0') r--;
		printf("%d\n", (r - l + 1) - cnt);
	}
	return 0;
}