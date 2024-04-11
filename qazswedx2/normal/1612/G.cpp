#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
/*int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x
	}
}*/
int n,c[1000005],tmp[10000005],*vis=tmp+5000000,fr[2000005],pn=2e6;
int main()
{
	fr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	scanf("%d",&n);
	int mn=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		c[i]--;
		vis[-c[i]]++;
		vis[c[i]+2]--;
		mn=min(mn,-c[i]);
		mx=max(mx,c[i]+2);
	}
	for(int i=mn;i<=mx;i++)
		vis[i]+=vis[i-2];
	int nw=0,ans1=0,ans2=1;
	for(int i=mn;i<=mx;i++)
	{
		ans2=1ll*ans2*fr[vis[i]]%mod;
	//	printf("vis=%d\n",vis);
		ans1=(ans1+1ll*(i+mod)%mod*(1ll*(2ll*nw+1+vis[i])*vis[i]/2%mod)%mod)%mod;
		nw=(nw+vis[i])%mod;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}