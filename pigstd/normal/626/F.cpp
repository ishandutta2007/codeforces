#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=1e3+10;
const int N=210;
int n,m,a[M],dp[N][N][M];

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	dp[1][1][0]=dp[1][0][0]=1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=i;j++)
			for (int k=0;k<=m;k++)
			{
				int d=a[i]-a[i-1];
				if (k-j*d>=0)
					dp[i][j][k]=(dp[i][j][k]+1ll*dp[i-1][j][k-j*d]*(j+1)%Mod)%Mod;
				if (k-(j-1)*d>=0&&j>=1)
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-(j-1)*d])%Mod;
				if (k-(j+1)*d>=0)
					dp[i][j][k]=(dp[i][j][k]+1ll*dp[i-1][j+1][k-(j+1)*d]*(j+1)%Mod)%Mod;
			}int ans=0;
	for (int i=0;i<=m;i++)
		ans=(ans+dp[n][0][i])%Mod;
	cout<<ans<<endl;
	return 0;
}