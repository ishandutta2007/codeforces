#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
int n, m, dp[3000][3001], ans;
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	n=s.size(), m=t.size();
	dp[0][m]=2;
	for (int i=0; i<m; ++i)
		if (s[0]==t[i])
			dp[0][i]=2;
	if (t.size()==1)
		ans+=dp[0][0];
	for (int i=1; i<n; ++i) {
		dp[i][m]=2*dp[i-1][m]%M;
		for (int j=0; j<m; ++j) {
			if (s[i]==t[j])
				dp[i][j]=dp[i-1][j+1];
			if (i+j<m&&s[i]==t[j+i]||i+j>=m)
				dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
		}
		if (i+1>=t.size())
			ans=(ans+dp[i][0])%M;
	}
	/*for (int i=0; i<n; ++i) {
		for (int j=0; j<=m; ++j)
			cout << dp[i][j] << " ";
		cout << "\n";
	}*/
	cout << ans;
	return 0;
}