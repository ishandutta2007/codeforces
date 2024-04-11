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
int n,m,ans=0,fr[1000005],infr[1000005],pn=1e6;
int C(int x,int y)
{
	if(x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int getans(int x)
{
	return C(x-1,m-1);
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%d%d",&n,&m);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans=addmod(ans+1ll*(r-l+1)*getans(n/l)%mod);
	}
	printf("%d",ans);
	return 0;
}