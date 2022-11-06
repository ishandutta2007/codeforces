#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[100005], r[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, mfs = 0;
	string s;
	cin >> n >> s;
	for (int i = n - 1; i >= 0; i--)
		cnt[i] = (s[i] == 'G') + cnt[i + 1];
	for (int i = 0; i < n; i++) cnt[i] -= s[i] == 'G';
	for (int i = 0, fs = -1, rs = 0; i < n; i++) {
		if (s[i] == 'G') rs++;
		else rs = 0;
		r[i] = rs;
		mfs = max(mfs, rs);
		if (s[i] == 'G') {
			if (cnt[i]) mfs = max(mfs, rs + (i - rs - 1 >= 0 ? r[i - rs - 1] : 0) + 1);
			else if (fs != -1) {
				int lpos = max(fs, (i - rs - 1 >= 0 ? i - rs - 1 - r[i - rs - 1] : 0));
				mfs = max(mfs, i - lpos);
			}
		} else {
			if (cnt[i]) mfs = max(mfs, (i ? r[i - 1] : 0) + 1);
			else if (fs != -1) {
				int lpos = max(fs, i - 1 - r[i - 1]);
				mfs = max(mfs, i - lpos);
			}
		}
		if (s[i] == 'G' && fs == -1) fs = i;
	}
	cout << mfs << '\n';
}