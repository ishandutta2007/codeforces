#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		int cnt1 = count(s.begin(), s.end(), '<');
		int cnt2 = count(s.begin(), s.end(), '>');
		cnt1 += count(s.begin(), s.end(), '-');
		cnt2 += count(s.begin(), s.end(), '-');
		if (cnt1 == n || cnt2 == n) {
			cout << n << "\n";
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += s[i] == '-' || s[(i + n - 1) % n] == '-';
		}
		cout << ans << "\n";
	}
	return 0;
}