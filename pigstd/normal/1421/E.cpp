#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2e5+10;
int a[M],n,dp[M][3][2][2];
// 0 - 1 +
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	if (n==1)return printf("%lld\n",a[1]),0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<3;j++)
			for (int l=0;l<2;l++)
				for (int k=0;k<2;k++)dp[i][j][l][k]=-inf;
	dp[1][1][1][0]=a[1],dp[1][2][0][0]=-a[1];
	for (int i=1;i<n;i++)
		for (int j=0;j<3;j++)
			for (int k=0;k<2;k++)
			{
				dp[i+1][(j+1)%3][1][k|1]=max(dp[i+1][(j+1)%3][1][k|1],dp[i][j][1][k]+a[i+1]);
				dp[i+1][(j+1)%3][1][k]=max(dp[i+1][(j+1)%3][1][k],dp[i][j][0][k]+a[i+1]);
				dp[i+1][(j+2)%3][0][k|1]=max(dp[i+1][(j+2)%3][0][k|1],dp[i][j][0][k]-a[i+1]);
				dp[i+1][(j+2)%3][0][k]=max(dp[i+1][(j+2)%3][0][k],dp[i][j][1][k]-a[i+1]);
			}
	cout<<max(dp[n][1][0][1],dp[n][1][1][1])<<endl;
	return 0;
}