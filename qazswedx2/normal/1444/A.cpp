#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t;
ll p,q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&p,&q);
		ll nw=q;
		ll ans=1;
		for(int i=2;1ll*i*i<=nw;i++)
			if(nw%i==0)
			{
				while(nw%i==0) nw/=i;
				ll np=p;
				while(np%q==0&&np%i==0) np/=i;
				if(np%q!=0) ans=max(ans,np);
			}
		if(nw!=1)
		{
			ll np=p;
			while(np%q==0&&np%nw==0) np/=nw;
			if(np%q!=0) ans=max(ans,np);
		}
		printf("%lld\n",ans);
	}
	return 0;
}