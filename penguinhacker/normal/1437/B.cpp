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
		int ans = 0;
		for (int i = 1; i < n; ++i) ans += s[i] == s[i - 1];
		ans = (ans + 1) / 2;
		cout << ans << "\n";
	}
	return 0;
}