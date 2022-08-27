#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[100005],c[20000005],prime[20000005],pt,pn=2e7,p[20000005];
ll f[20000005];
int main()
{
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	for(int i=1;i<=pt;i++)
	{
		for(int j=pn/prime[i];j>0;j--)
			c[j]+=c[j*prime[i]];
	//	for(int i=1;i<=200;i++)
	//	if(i<=200)printf("i=%d,c=%d,f=%lld\n",i,c[i],f[i]); 
	}
	f[1]=n;
	ll ans=0;
	for(int i=1;i<=pn;i++)
	{
		ans=max(ans,f[i]);
	//	if(i<=200)printf("i=%d,c=%d,f=%lld\n",i,c[i],f[i]); 
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			int u=i*prime[j];
			f[u]=max(f[u],f[i]+1ll*(u-i)*c[u]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}