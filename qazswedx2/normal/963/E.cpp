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
int n,m,a[4],p[4],pn=51,f[105][105][105],g[105][105],c[105];
inline int check(int x,int y)
{
	return x*x+y*y<=n*n;
}
void gauss()
{
	for(int i=0;i<=m;i++)
	{
		int nw=i;
		while(nw<=m&&!g[nw][i]) nw++;
		if(nw!=i)
		{
			for(int j=0;j<=m+1;j++)
				swap(g[i][j],g[nw][j]);
		}
		int inv=fpow(g[i][i],mod-2);
		for(int j=i;j<=m+1;j++)
			g[i][j]=1ll*g[i][j]*inv%mod;
		for(int j=0;j<=m;j++)
		{
			if(i==j) continue;
			int q=g[j][i];
			for(int k=i;k<=m+1;k++)
				g[j][k]=submod(g[j][k]-1ll*q*g[i][k]%mod);
		}
	}
	for(int i=0;i<=m;i++)
		c[i]=g[i][m+1];
}
int main()
{
	scanf("%d%d%d%d%d",&n,&a[0],&a[1],&a[2],&a[3]);
	int inv=fpow(a[0]+a[1]+a[2]+a[3],mod-2);
	for(int i=0;i<4;i++)
		p[i]=1ll*a[i]*inv%mod;
	int inv3=fpow(p[3],mod-2);
	for(int i=-n;i<=n+1;i++)
		for(int j=-n;j<=n;j++)
		{
			if(check(i,j)&&!check(i-1,j))
				f[i+pn][j+pn][j+pn]=1;
			else if(check(i,j)||(!check(i,j)&&check(i-1,j)))
			{
				for(int k=-n;k<=n+1;k++)
				{
					int q=(f[i-1+pn][j+pn][k+pn]-1ll*f[i-1+pn][j-1+pn][k+pn]*p[0]
					-1ll*f[i-2+pn][j+pn][k+pn]*p[1]-1ll*f[i-1+pn][j+1+pn][k+pn]*p[2])%mod;
					if(k==n+1) q--;
					q=(q+mod)%mod;
					f[i+pn][j+pn][k+pn]=1ll*q*inv3%mod;
				}
				if(!check(i,j))
				{
					for(int k=-n;k<=n;k++)
						g[j+n][k+n]=f[i+pn][j+pn][k+pn];
					g[j+n][n+1+n]=(mod-f[i+pn][j+pn][n+1+pn])%mod;
				}
			}
		}
	m=2*n;
	gauss();
	int ans=f[pn][pn][n+1+pn];
	for(int i=-n;i<=n;i++)
		ans=addmod(ans+1ll*f[pn][pn][i+pn]*c[i+n]%mod);
	printf("%d\n",ans);
	return 0;
}