#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,f[100005],fr[100005],infr[100005]; 
ll a[100005];
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x; 
}
int getans(int x,int y)
{
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
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
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			char ch;
			scanf(" %c",&ch);
			a[j]|=((ll)(ch-'0')<<(ll)(i-1));
		}
	sort(a+1,a+n+1);
	fr[0]=infr[0]=1;
	for(int i=1;i<=n;i++)
	{
		fr[i]=1ll*i*fr[i-1]%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]=addmod(f[i]+1ll*getans(i-1,j-1)*f[i-j]%mod);
	int ans=1,ct=1;
	ll val=a[1];
	a[n+1]=-1;
	for(int i=2;i<=n+1;i++)
		if(val==a[i]) ct++;
		else
		{
			ans=1ll*ans*f[ct]%mod;
			ct=1;
			val=a[i];
		}
	printf("%d",ans);
	return 0;
}