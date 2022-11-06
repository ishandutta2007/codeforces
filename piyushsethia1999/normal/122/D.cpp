#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	string s; cin >> s;
	for (int i = 1; i < s.size() && k; ++i) {
		if (s[i - 1] == '4' && s[i] == '7') {
			if (i & 1) {
				if (i + 1 < n && s[i + 1] == '7') {
					if (k & 1) {
						s[i] = '4';
					} 
					k = 0;
				} else {
					s[i] = '4';
					k--;
				}
			} else {
				if (i - 2 >= 0 && s[i - 2] == '4') {
					if (k & 1) {
						s[i - 1] = '7';
					} 
					k = 0;
				} else {
					s[i - 1] = '7';
					k--;
				}
			}
		}
	}
	cout << s;
}