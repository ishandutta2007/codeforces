#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int t,n,f[1000005],g[1000005];
ll a[1000005];
map<ll,int> mp;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			f[i]=g[i]=0;
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]+=a[i-1];
		}
		f[0]=g[0]=1;
		mp[a[0]]=1;
		for(int i=1;i<=n;i++)
		{
			f[i]=(2ll*f[i-1]-g[i-1]+mod)%mod;
			g[i]=mp[a[i]];
		//	printf("i=%d,f=%d,g=%d\n",i,f[i],g[i]);
			mp[a[i]]=(1ll*mp[a[i]]+f[i]-g[i]+mod)%mod;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}