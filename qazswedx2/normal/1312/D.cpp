#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,fr[500005],infr[500005],pw[500005],pn=5e5;
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
int getans(int x,int y)
{
	if(x<y||x<0||y<0) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	pw[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
		pw[i]=2ll*pw[i-1]%mod;
	}
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=2;i<=m;i++)
	{
		int nw=i-1;
		nw=1ll*nw*getans(i-2,n-3)%mod*pw[n-3]%mod;
		ans=addmod(ans+nw);
	}
	printf("%d\n",ans);
	return 0;
}