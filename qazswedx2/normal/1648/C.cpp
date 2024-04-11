#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=998244353;
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
int fr[1000005],infr[1000005],pn=1e6;
int n,m,len=2e5,a[1000005],b[1000005],sum[1000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	for(int i=x;i<=len;i+=lowbit(i))
		sum[i]=addmod(sum[i]+v);
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans=addmod(ans+sum[i]);
	return ans;
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
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	int mul=1;
	for(int i=1;i<=len;i++)
	{
		mul=1ll*mul*infr[a[i]]%mod;
		modify(i,a[i]);
	}
	int tans=0;
	for(int i=1;i<=m;i++)
	{
		if(i==n+1)
		{
			tans=addmod(tans+1);
			break;
		}
		int u=b[i];
		int q=query(u-1);
	//	printf("i=%d,u=%d,q=%d,mul=%d,%lld\n",i,u,q,mul,1ll*q*mul%mod*fr[n-i]%mod);
		tans=addmod(tans+1ll*q*mul%mod*fr[n-i]%mod);
		if(!a[u]) break;
		modify(u,mod-1);
		mul=1ll*mul*a[u]%mod;
		a[u]--;
	}
	printf("%d\n",tans);
	return 0; 
}