#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x; 
}
int n,m,ans,c[5005][5005],pn=5e3;
int main()
{
	for(int i=0;i<=pn;i++)
		c[i][0]=1;
	for(int i=1;i<=pn;i++)
		for(int j=1;j<=pn;j++)
			c[i][j]=addmod(c[i-1][j-1]+c[i-1][j]);
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		int nw=0,nans=0;
		for(int j=2;j<=m;j++)
		{
			nw=addmod(nw+1ll*c[i+j-3][i-1]*c[i-2+m-j+1][i-2]%mod);
			nans=addmod(nans+1ll*c[n-i+1+m-j][n-i+1]*c[n-i+j-1][n-i]%mod*nw%mod);
		}
		ans=addmod(ans+nans);
	}
	for(int i=2;i<=m;i++)
	{
		int nw=0,nans=0;
		for(int j=2;j<=n;j++)
		{
			nans=addmod(nans+1ll*c[m-i+1+n-j][m-i+1]*c[m-i+j-1][m-i]%mod*nw%mod);
			nw=addmod(nw+1ll*c[i+j-3][i-1]*c[i-2+n-j+1][i-2]%mod);
		}
		ans=addmod(ans+nans);
	}
	ans=2*ans%mod;
	printf("%d\n",ans);
	return 0;
}