#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
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
int T,n,m,k,pn=2e6,fr[2000005],infr[2000005],pw[2000005],inv2;
int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	inv2=fpow(2,mod-2);
	pw[0]=1;
	for(int i=1;i<=pn;i++)
		pw[i]=1ll*inv2*pw[i-1]%mod;
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		int ans=0;
		if(n==m)
		{
			ans=1ll*n*k%mod;
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=m;i++)
		{
			int nw=1ll*pw[n-i]*C(n-i-1,m-i)%mod;
			ans=(ans+1ll*nw*i)%mod;
		}
		ans=1ll*ans*k%mod;
		printf("%d\n",ans);
	}
	return 0;
}