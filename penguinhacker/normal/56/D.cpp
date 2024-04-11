#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
int n, m, dp[mxN+1][mxN+1], last[mxN+1][mxN+1], cnt[mxN+1][mxN+1];
string s, t;
char rep[mxN+1][mxN+1];

void solve(int i, int j) {
	if (!i&&!j)
		return;
	if (last[i][j]==0) {
		solve(i-1, j);
		cout << "DELETE " << cnt[i][j]+1 << "\n";
	} else if (last[i][j]==1) {
		solve(i, j-1);
		cout << "INSERT " << cnt[i][j] << " " << t[j-1] << "\n";
	} else {
		solve(i-1, j-1);
		if (rep[i][j]!='0')
			cout << "REPLACE " << cnt[i][j] << " " << rep[i][j] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	n=s.size(), m=t.size();
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0]=0;
	for (int i=0; i<=n; ++i)
		for (int j=0; j<=m; ++j) {
			if (i&&dp[i-1][j]+1<dp[i][j]) {
				dp[i][j]=dp[i-1][j]+1;
				last[i][j]=0;
				cnt[i][j]=cnt[i-1][j];
			}
			if (j&&dp[i][j-1]+1<dp[i][j]) {
				dp[i][j]=dp[i][j-1]+1;
				last[i][j]=1;
				cnt[i][j]=cnt[i][j-1]+1;
			}
			if (i&&j&&dp[i-1][j-1]+(s[i-1]!=t[j-1])<dp[i][j]) {
				dp[i][j]=dp[i-1][j-1]+(s[i-1]!=t[j-1]);
				last[i][j]=2;
				cnt[i][j]=cnt[i-1][j-1]+1;
				rep[i][j]=s[i-1]!=t[j-1]?t[j-1]:'0';
			}
		}
	cout << dp[n][m] << "\n";
	solve(n, m);
	return 0;
}