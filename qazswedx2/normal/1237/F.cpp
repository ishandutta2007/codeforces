#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
int n,m,q,a[100005],b[100005],f[4005][4005],g[4005][4005];
int fr[100005],infr[100005],pn=1e5,ctx,cty;
int C(int x,int y)
{
	if(x<y||x<0||y<0) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		a[x]=a[xx]=1;
		b[y]=b[yy]=1;
	}
	for(int i=1;i<=n;i++)
		ctx+=!a[i];
	for(int i=1;i<=m;i++)
		cty+=!b[i];
	a[0]=b[0]=1;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[i][j]=f[i-1][j];
			if(j&&!a[i]&&!a[i-1]) f[i][j]=addmod(f[i][j]+f[i-2][j-1]);
	//		printf("%d ",f[i][j]);
		}
	//	printf("\n");
	}
//	printf("\n");
	g[0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			g[i][j]=g[i-1][j];
			if(j&&!b[i]&&!b[i-1]) g[i][j]=addmod(g[i][j]+g[i-2][j-1]);
		//	printf("%d ",g[i][j]);
		}
	//	printf("\n");
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i+2*j>ctx||j+2*i>cty) continue;
			int ans1,ans2;
			ans1=1ll*f[n][j]*C(ctx-2*j,i)%mod;
			ans2=1ll*g[m][i]*C(cty-2*i,j)%mod;
			ans=addmod(ans+1ll*ans1*ans2%mod*fr[i]%mod*fr[j]%mod);
		}
	printf("%d\n",ans);
	return 0;
}