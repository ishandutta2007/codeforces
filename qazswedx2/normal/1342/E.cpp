#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
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
int n,fr[500005],infr[500005],f[500005],pn=5e5;
ll k;
int C(int x,int y)
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
	scanf("%d%lld",&n,&k);
	if(n<=k)
	{
		printf("0");
		return 0;
	}
	//k=n-k;
	for(int i=k;i<=n;i++)
		f[i]=1ll*C(n,n-i)*fpow(n-i,n)%mod;
	int ans=0;
	for(int i=k;i<=n;i++)
		if((i-k)%2==0) ans=addmod(ans+1ll*C(i,k)*f[i]%mod);
		else ans=submod(ans-1ll*C(i,k)*f[i]%mod);
	if(k) ans=2ll*ans%mod; 
	printf("%d",ans);
	return 0;
}