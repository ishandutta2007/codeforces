#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

//bool tc6=0;

void solve(int tc) {
	int n;
	string s, t;
	cin >> n >> s >> t;
	/*if (tc==1&&s=="q")
		tc6=1;
	if (tc6&&tc==52) {
		cout << s << "+" << t << endl;
		exit(0);
	}*/
	/*
	1
	5
	dbdca
	dcdab
	
	*/
	vector<int> cnt(26);
	for (char c : s)
		++cnt[c-'a'];
	for (char c : t)
		--cnt[c-'a'];
	if (count(cnt.begin(), cnt.end(), 0)!=26) {
		cout << "-1\n";
		return;
	}
	vector<vector<int>> dp(n+1, vector<int>(n+1)); // end position i in t, ___i, max subsequence in s up to j
	int ans=0;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j) {
			dp[i][j]=max(dp[i][j-1], (s[j-1]==t[i-1]?dp[i-1][j-1]+(s[j-1]==t[i-1]):0));
			ans=max(ans, dp[i][j]);
		//	cout << i << " " << j << " " << dp[i][j] << endl;
		}
	cout << n-ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i)
		solve(i);
	return 0;
}