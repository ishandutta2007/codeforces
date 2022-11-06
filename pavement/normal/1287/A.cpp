#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	string s;
	cin >> T;
	while (T--) {
		cin >> N >> s;
		int mlen = 0, clen = 0, pos = N;
		for (int i = 0; i < N; i++) {
			if (s[i] == 'A') {
				pos = i;
				break;
			}
		}
		for (int i = pos; i < N; i++) {
			if (s[i] == 'A') {
				mlen = max(mlen, clen);
				clen = 0;
			} else clen++;
		}
		cout << max(mlen, clen) << '\n';
	}
}