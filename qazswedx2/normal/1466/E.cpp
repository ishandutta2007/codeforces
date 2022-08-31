#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int t,n,f[105];
ll a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			for(ll j=0;j<=60;j++)
				if((1ll<<j)&a[i])
					f[j]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int nw=0,nw2=0;
			for(ll j=0;j<=60;j++)
				if((1ll<<j)&a[i])
					nw=addmod(nw+(1ll<<j)%mod*f[j]%mod);
			for(ll j=0;j<=60;j++)
				if(!((1ll<<j)&a[i]))
					nw2=addmod(nw2+(1ll<<j)%mod*f[j]%mod);
			nw2=addmod(nw2+a[i]%mod*n%mod);
			ans=addmod(ans+1ll*nw*nw2%mod);
		}
		printf("%d\n",ans);
	}
	return 0;
}