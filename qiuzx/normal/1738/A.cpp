//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,b[2][N],cnt[2],a[N];
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		cnt[0]=cnt[1]=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			ll x;
			scanf("%lld",&x);
			b[a[i]][cnt[a[i]]++]=x;
		}
		sort(b[0],b[0]+cnt[0]);
		sort(b[1],b[1]+cnt[1]);
		if(cnt[0]==cnt[1])
		{
			ll ans=0;
			for(i=0;i<cnt[0];i++)
			{
				ans+=b[0][i]*2;
			}
			for(i=0;i<cnt[1];i++)
			{
				ans+=b[1][i]*2;
			}
			printf("%lld\n",ans-min(b[0][0],b[1][0]));
		}
		else
		{
			if(cnt[0]<cnt[1])
			{
				ll ans=0;
				for(i=0;i<cnt[0];i++)
				{
					ans+=b[0][i]*2;
				}
				for(i=0;i<cnt[1];i++)
				{
					ans+=b[1][i];
					if(cnt[1]-i<=cnt[0])
					{
						ans+=b[1][i];
					}
				}
				printf("%lld\n",ans);
			}
			else
			{
				ll ans=0;
				for(i=0;i<cnt[1];i++)
				{
					ans+=b[1][i]*2;
				}
				for(i=0;i<cnt[0];i++)
				{
					ans+=b[0][i];
					if(cnt[0]-i<=cnt[1])
					{
						ans+=b[0][i];
					}
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}