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
int n,m,sa[200005],rk[200005],fr[1000005],infr[1000005],pn=1e6;
int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
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
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sa[i]);
		sa[i]++;
		rk[sa[i]]=i;
	}
	int nw=m;
	for(int i=1;i<n;i++)
	{
		if(rk[sa[i]+1]<rk[sa[i+1]+1])
			nw++;
	}
	printf("%d\n",C(nw,n)); 
	return 0;
}