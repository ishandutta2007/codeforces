// Author: Little09
// Problem: E. Swap and Take
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) ((x)&(-(x)))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=505;
int n,m; 
int a[N],dp[2][N][N],s[2][N][N];
//dp[i][j][k] [1,i] j a_k 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=0;i<1;i++) for (int j=0;j<N;j++) for (int k=0;k<N;k++) dp[i][j][k]=-1e9,s[i][j][k]=-1e9;
	dp[0][0][0]=0,s[0][0][0]=0;
	for (int k=1;k<=n;k++) s[0][0][k]=max(s[0][0][k-1],dp[0][0][k]);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<N;j++) for (int k=0;k<N;k++) dp[i&1][j][k]=-1e9,s[i&1][j][k]=-1e9;
		for (int j=0;j<=i;j++)
		{
			for (int k=0;k<=n;k++)
			{
				//if (i==2&&j==0&&k==5) cout << dp[i&1][j][k] << endl;
				dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j][k]+a[k]);
				//if (i==2&&j==0&&k==5) cout << dp[i&1][j][k] << endl;
				if (k>=i) 
				{
					int v=j+(k-i-1);
					//if (i==2&&j==0&&k==5) cout << v << endl;
					if (v>=0&&v<=n) dp[i&1][j][k]=max(dp[i&1][j][k],s[i-1&1][v][k-1]+a[k]);
				}
				//if (i==2&&j==0&&k==5) cout << dp[i&1][j][k] << endl;
			}
			s[i&1][j][0]=dp[i&1][j][0];
			for (int k=1;k<=n;k++) s[i&1][j][k]=max(s[i&1][j][k-1],dp[i&1][j][k]);
		}
		//cout << dp[i&1][2][0] << endl;
	}
	int ans=0;
	for (int j=0;j<=n;j++) for (int k=0;k<=n;k++) ans=max(dp[n&1][j][k],ans);
	cout << ans;
	return 0;
}