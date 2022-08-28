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
int n,a[500005],cnt[10000005],pn=1e7,f[10000005],mu[10000005],prime[2000005],pt;
int g[10000005];
bool p[10000005];
int main()
{
	mu[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,mu[i]=-1;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	f[1]=1;
	scanf("%d",&n);
	for(int i=2;i<=pn;i++)
		f[i]=addmod(2*f[i-1]);
	for(int i=1;i<=pn;i++)
		g[i]=submod(1ll*f[i]*(2ll*n-i+mod)%mod-n);
	for(int i=1;i<=pn;i++)
		f[i]=1ll*submod(f[i]-1)*i%mod;
	//for(int i=2;i<=pn;i++)
	//	f[i]=addmod(f[i]+f[i-1]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=pn;i++)
		for(int j=i*2;j<=pn;j+=i)
			cnt[i]+=cnt[j];
	int ans=0;
	for(int i=2;i<=pn;i++)
	{
		//if(i<=3) printf("i=%d,cnt=%d,f=%d,g=%d\n",i,cnt[i],f[cnt[i]],g[cnt[i]]);
		if(mu[i]==1)
		{
			ans=addmod(ans+f[cnt[i]]);
			ans=submod(ans-g[cnt[i]]);
		}
		if(mu[i]==-1) 
		{
			ans=submod(ans-f[cnt[i]]);
			ans=addmod(ans+g[cnt[i]]);
		}
	}
	printf("%d",ans);
	return 0;
}