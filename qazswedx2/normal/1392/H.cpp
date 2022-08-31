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
int n,m,fr[4000005],infr[4000005],inv[4000005],pn=4e6;
inline int C(int x,int y)
{
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	for(int i=1;i<=pn;i++)
		inv[i]=1ll*infr[i]*fr[i-1]%mod;
	scanf("%d%d",&n,&m);
	int ans1=0,ans2=0,mul=1;
	for(int i=0;i<=n;i++)
	{
		ans1=addmod(ans1+1ll*mul*m%mod*inv[n+m-i]%mod*(i+1)%mod);
		mul=1ll*mul*(n-i)%mod*fpow(n+m-i,mod-2)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		int q=1ll*C(n,i)*(m+i)%mod*inv[i]%mod;
		if(i%2) ans2=addmod(ans2+q);
		else ans2=submod(ans2-q);
	}
	ans1=1ll*ans1*ans2%mod;
	printf("%d\n",ans1);
	return 0;
}