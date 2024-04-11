#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF=1e9;
int n, k;
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> s >> t;
	if (t[0]==t[1]) {
		int x=count(s.begin(), s.end(), t[0])+k;
		x=min(x, n);
		cout << x*(x-1)/2;
		return 0;
	}

	vector<vector<int>> dp(n+1, vector<int>(k+1, -INF)); //number of "1s" and changes made
	dp[0][0]=0;
	for (int i=0; i<n; ++i) {
		int cost1=t[0]!=s[i];
		int cost2=t[1]!=s[i];
		vector<vector<int>> last=dp;
		for (int a=0; a<=i+1; ++a) for (int b=0; b<=min(k, i+1); ++b) {
			if (b-cost1>=0&&a>0) dp[a][b]=max(dp[a][b], last[a-1][b-cost1]);
			if (b-cost2>=0) dp[a][b]=max(dp[a][b], last[a][b-cost2]+a);
		}
	}
	int ans=0;
	for (int i=0; i<=n; ++i) ans=max(ans, *max_element(dp[i].begin(), dp[i].end()));
	cout << ans;
	return 0;
}