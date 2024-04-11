#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,T,a[3][100005],at[3],f[3][55][3005],fr[100005],infr[100005],pn=1e5;
int g[55][55][3005],dp[55][55][55][3];
void solve(int x)
{
	f[x][0][0]=1;
	for(int i=1;i<=at[x];i++)
	{
		int v=a[x][i];
		for(int j=n;j>0;j--)
			for(int k=T;k>=v;k--)
				f[x][j][k]=addmod(f[x][j][k]+f[x][j-1][k-v]);
	}
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=n;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%d",&n,&T);
	dp[1][0][0][0]=1;
	dp[0][1][0][1]=1;
	dp[0][0][1][2]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				for(int l=0;l<3;l++)
				{
					if(l!=0) dp[i+1][j][k][0]=(dp[i+1][j][k][0]+1ll*(i+1)*dp[i][j][k][l])%mod;
					if(l!=1) dp[i][j+1][k][1]=(dp[i][j+1][k][1]+1ll*(j+1)*dp[i][j][k][l])%mod;
					if(l!=2) dp[i][j][k+1][2]=(dp[i][j][k+1][2]+1ll*(k+1)*dp[i][j][k][l])%mod;
				}
	for(int i=1;i<=n;i++)
	{
		int x,y; 
		scanf("%d%d",&x,&y);
		a[y-1][++at[y-1]]=x; 
	}
	g[0][0][0]=1;
	for(int i=1;i<=at[0];i++)
	{
		int v=a[0][i];
		for(int j=n;j>0;j--)
			for(int k=T;k>=v;k--)
				g[0][j][k]=addmod(g[0][j][k]+g[0][j-1][k-v]);
	}
	for(int l=0;l<=n;l++)
	for(int i=1;i<=at[1];i++)
	{
		int v=a[1][i];
		for(int j=n;j>0;j--)
			for(int k=T;k>=v;k--)
				g[j][l][k]=addmod(g[j][l][k]+g[j-1][l][k-v]);
	}
	solve(2);
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
			{
				int nw=0;
				for(int l=0;l<=T;l++)
				{
					int q=1ll*g[i][j][l]*f[2][k][T-l]%mod;
			//		printf("g=%d,f=%d\n",g[i][j][l],f[2][k][T-l]);
					nw=addmod(nw+q);
				}
			//	printf("i=%d,j=%d,k=%d,nw=%d,dp=%d\n",i,j,k,nw,dp[i][j][k]);
				ans=(ans+1ll*nw*(1ll*dp[i][j][k][0]+dp[i][j][k][1]+dp[i][j][k][2]))%mod;
			}
	printf("%d\n",ans);
	return 0;
}