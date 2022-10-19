#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n,k,l1,r1,l2,r2,getit,movemax,maxres,alrhave;
int main(){
	ll T,i,ta,ans,tk;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		scanf("%lld%lld",&l1,&r1);
		scanf("%lld%lld",&l2,&r2);
		if(l1>l2)
		{
			swap(l1,l2);
			swap(r1,r2);
		}
		alrhave=min(r1,r2)-l2;
		maxres=max(r1,r2)-l1;
		if(alrhave<=0)
		{
			getit=-alrhave;
			alrhave=0;
			movemax=maxres+alrhave;
		}
		else
		{
			getit=0;
			movemax=maxres-alrhave;
		}
		k-=alrhave*n;
		if(k<=0)
		{
			puts("0");
			continue;
		}
		ans=LINF;
		for(i=1;i<=n;i++)
		{
			ta=getit*i;
			tk=k;
			if(tk>movemax*i)
			{
				tk-=movemax*i;
				ta+=movemax*i;
			}
			else
			{
				ta+=tk;
				ans=min(ans,ta);
				continue;
			}
			ta+=tk*2;
			ans=min(ans,ta);
		}
		printf("%lld\n",ans);
	}
	return 0;
}