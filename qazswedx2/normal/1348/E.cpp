#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1005],b[1005],c[1005][1005],g[1005][1005];
ll f[1005][1005],sum[1005];
inline int submod(int x)
{
	return x<0?x+m:x;
}
inline int getans(int x)
{
	return x<0;
}
int main()
{
	memset(f,0xcf,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sum[i]=sum[i-1]+a[i]+b[i];
		for(int j=0;j<m;j++)
		{
			int v=(a[i]%m+b[i]%m-j+m)%m;
			if(a[i]>=j&&v<=b[i])
				c[i][j]=(1ll*a[i]+1ll*b[i]-j-v)/m;
			else c[i][j]=-1;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			g[i][j]=(sum[i]-j)%m;
		for(int j=0;j<m;j++)
			if(c[i][j]!=-1)
				for(int k=0;k<m;k++)
				{
					int nw=submod(k-j);
					f[i][k]=max(f[i][k],f[i-1][nw]+c[i][j]+getans(k-nw)+getans(g[i][k]-g[i-1][nw]));
				}
	}
	ll tans=0;
	for(int i=0;i<m;i++)
	{
	//	ll v=(suma+sumb-i+m)%m;
	//	if(suma>=i&&sumb>=v) tans=max(tans,f[n][i]+(suma-i)/m+(sumb-v)/m);
		tans=max(tans,f[n][i]);
	}
	printf("%lld",tans);
	return 0;
}