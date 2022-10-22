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

const int M=760;
int n,m,a[M],dp[M][M];

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[n+1][0]=0;
	for (int i=n;i>=1;i--)
		for (int j=0;j<=n;j++)
			dp[i][j]=min(dp[i+1][j],max(0ll,dp[i+1][j-1]-a[i]));
//	for (int i=0;i<=n;i++)
//		cout<<dp[1][i]<<' ';
//	puts("");
	for (int i=1;i<=m;i++)
	{
		int tl=0,tr=n,ans,x=read();
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (dp[1][Mid]>x)tr=Mid-1;
			else tl=Mid+1,ans=Mid;
		}cout<<n-ans<<endl;
	}
	return 0;
}