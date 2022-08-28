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
int n,m,sum,pn=2e5,fr[200005],infr[200005];
int getans(int x,int y)
{
	int ans=0;
	for(int i=1;i<=y;i++)
		if((y-i)%2==0) ans=addmod(ans+1ll*fpow(i,x)*infr[i]%mod*infr[y-i]%mod);
		else ans=submod(ans-1ll*fpow(i,x)*infr[i]%mod*infr[y-i]%mod);
//	printf("x=%d,y=%d,ans=%d\n",x,y,ans);
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
		sum=addmod(sum+x);
	}
	int ans=0;
	ans=addmod(getans(n,m)+1ll*(n-1)*getans(n-1,m)%mod);
	ans=1ll*ans*sum%mod;
	printf("%d",ans);
	return 0;
}