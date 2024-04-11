#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, dp[mxN][4];
string g[2];

int get_mask(int i) {
	return (g[0][i]=='*')+2*(g[1][i]=='*');
}

void solve() {
	cin >> n >> g[0] >> g[1];
	int s=0, t=n-1;
	for (; g[0][s]=='.'&&g[1][s]=='.'; ++s);
	for (; g[0][t]=='.'&&g[1][t]=='.'; --t);
	g[0]=g[0].substr(s, t-s+1);
	g[1]=g[1].substr(s, t-s+1);
	n=t-s+1;
	//cout << s << " " << t << endl;
	memset(dp, 0x3f, n*16);
	dp[0][get_mask(0)]=0;
	for (int i=0; i<n; ++i) {
		dp[i][1]=min(dp[i][1], dp[i][3]+1);
		dp[i][2]=min(dp[i][2], dp[i][3]+1);
		dp[i][1]=min(dp[i][1], dp[i][2]+1);
		dp[i][2]=min(dp[i][2], dp[i][1]+1);
		if (i+1<n) {
			for (int j=1; j<4; ++j) {
				int x=j|get_mask(i+1);
				dp[i+1][x]=min(dp[i+1][x], dp[i][j]+__builtin_popcount(j));
			}
		}
		/*for (int j=1; j<4; ++j)
			cout << dp[i][j] << " ";
		cout << "\n";*/
	}
	cout << min(dp[n-1][1], dp[n-1][2]) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}