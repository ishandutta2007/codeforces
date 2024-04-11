#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1005][1005],len=3,s,x[1005],q;
ll f[1005],g[1005];
ll F(int X)
{
	ll ans=0;
	for(int i=1;i<=len;i++)
	{
		ll mul=g[x[i]];
		for(int j=1;j<=len;j++)
			if(i!=j)
				mul*=(X-x[j]);
		for(int j=1;j<=len;j++)
			if(i!=j)
				mul/=(x[i]-x[j]);
		ans+=mul;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i]+=a[i][j];
			g[i]+=1ll*a[i][j]*a[i][j];
		}
	for(int i=2;i<=n;i++)
		if(f[i]-f[i-1]==f[i+1]-f[i])
		{
			s=i-1;
			break;
		}
/*	for(int i=1;i<=n;i++)
	{
		printf("i=%d,f=%lld,%lld\n",i,f[i],f[s]+(i-s)*(f[s+1]-f[s]));
	}*/
	ll d=0;
	for(int i=1;i<=n;i++)
		if(f[i]!=f[s]+(i-s)*(f[s+1]-f[s]))
		{
			q=i;
			d=f[i]-(f[s]+(i-s)*(f[s+1]-f[s]));
		}
	x[1]=s,x[2]=s+1,x[3]=s+2;
	ll v=g[q]-F(q);
	ll ans=(v/d-d)/2;
//	printf("d=%lld,v=%lld,q=%d\n",d,v,q);
	printf("%d %lld\n",q-1,ans);
	return 0;
}