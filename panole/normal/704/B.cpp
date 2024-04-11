#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
long long f[2][5010];
int s,t,n,a[5010],b[5010],c[5010],d[5010],v[5010],x,y;

int main()
{
	scanf("%d%d%d",&n,&s,&t);
	for (int i=1; i<=n; i++) scanf("%d",&v[i]);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%d",&b[i]);
	for (int i=1; i<=n; i++) scanf("%d",&c[i]);
	for (int i=1; i<=n; i++) scanf("%d",&d[i]);
	for (int i=0; i<=n; i++) f[0][i]=f[1][i]=inf;
	x=1,y=0,f[0][1]=-2ll*v[1]+d[1]+b[1];
	f[0][1]-=(s<t?(v[t]-1ll*v[s]+b[s]+c[t]):(v[s]-1ll*v[t]+a[s]+d[t]));
	for (int i=2; i<n; i++)
	{
		x^=1,y^=1;
		for (int j=0; j<=n; j++) f[y][j]=inf;
		if (s==i)
		{
			if (s>t)
			{
				f[y][1]=f[x][1]+a[i]+d[i];
				for (int j=2; j<i; j++)
					f[y][j-1]=min(f[y][j-1],f[x][j]+2ll*v[i]+a[i]+c[i]),
					f[y][j]=min(f[y][j],f[x][j]+a[i]+d[i]);
			} else
			{
				f[y][1]=f[x][1]+b[i]+c[i];
				f[y][2]=f[x][1]-2ll*v[i]+d[i]+b[i];
				for (int j=2; j<i; j++)
					f[y][j]=min(f[y][j],f[x][j]+b[i]+c[i]),
					f[y][j+1]=min(f[y][j+1],f[x][j]-2ll*v[i]+d[i]+b[i]);
			}
			continue;
		}
		if (t==i)
		{
			if (s>t)
			{
				f[y][1]=f[x][1]+a[i]+d[i];
				f[y][2]=f[x][1]-2ll*v[i]+d[i]+b[i];
				for (int j=2; j<i; j++)
					f[y][j]=min(f[y][j],f[x][j]+a[i]+d[i]),
					f[y][j+1]=min(f[y][j+1],f[x][j]-2ll*v[i]+d[i]+b[i]);
			} else
			{
				f[y][1]=f[x][1]+b[i]+c[i];
				for (int j=2; j<i; j++)
					f[y][j]=min(f[y][j],f[x][j]+b[i]+c[i]),
					f[y][j-1]=min(f[y][j-1],f[x][j]+2ll*v[i]+a[i]+c[i]);
			}
			continue;
		}
		if (s<i&&i<t) f[y][1]=f[x][1]+a[i]+d[i]; else
		if (s>i&&i>t) f[y][1]=f[x][1]+b[i]+c[i]; else
		f[y][1]=min(f[x][1]+a[i]+d[i],f[x][1]+b[i]+c[i]);
		f[y][2]=f[x][1]-2ll*v[i]+d[i]+b[i];
		for (int j=2; j<i; j++)
			f[y][j-1]=min(f[y][j-1],f[x][j]+2ll*v[i]+a[i]+c[i]),
			f[y][j]=min(f[y][j],f[x][j]+min(a[i]+d[i],b[i]+c[i])),
			f[y][j+1]=min(f[y][j+1],f[x][j]-2ll*v[i]+d[i]+b[i]);
	}
	printf("%I64d\n",f[y][1]+2ll*v[n]+c[n]+a[n]);
	return 0;
}