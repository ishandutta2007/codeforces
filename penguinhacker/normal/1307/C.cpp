#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	ll ans=0, cnt[26]={}, dp[26][26]={};
	for (char c : s) {
		for (int i=0; i<26; ++i)
			dp[i][c-'a']+=cnt[i];
		ans=max(ans, ++cnt[c-'a']);
	}
	for (int i=0; i<26; ++i)
		for (int j=0; j<26; ++j)
			ans=max(ans, dp[i][j]);
	cout << ans << "\n";
	return 0;
}