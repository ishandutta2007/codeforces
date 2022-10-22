#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector<int> cnt(26);
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i % 2 == 0) {
			++cnt[s[i] - 'a'];
		}
		else {
			if (cnt[s[i] - 'A'] == 0) {
				++ans;
			}
			else {
				--cnt[s[i] - 'A'];
			}
		}
	}
	cout << ans;
	return 0;
}