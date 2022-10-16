#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s, t; cin >> s >> t;
	vector<int> cnt(256), cnts(256);
	for (char c: t) {
		cnt[c]++;
	}
	for (char c: s) {
		cnts[c]++;
	}
	int yay = 0, whoops = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		int k = min(cnt[c], cnts[c]);
		cnt[c] -= k; cnts[c] -= k;
		yay += k;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		int k = min(cnt[c], cnts[c]);
		cnt[c] -= k; cnts[c] -= k;
		yay += k;
	}

	for (char c = 'a', cc = 'A'; c <= 'z'; c++, cc++) {
		int k = min(cnt[c], cnts[cc]);
		cnt[c] -= k; cnts[cc] -= k;
		whoops += k;
	}
	for (char c = 'A', cc = 'a'; c <= 'Z'; c++, cc++) {
		int k = min(cnt[c], cnts[cc]);
		cnt[c] -= k; cnts[cc] -= k;
		whoops += k;
	}
	cout << yay << ' ' << whoops << '\n';

	return 0;
}