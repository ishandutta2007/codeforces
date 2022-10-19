//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,m,a[N],sum=0,ans;
int main(){
	ll i,x,y,p;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a,a+n);
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		ans=LINF*(ll)4;
		p=lower_bound(a,a+n,x)-a;
		if(p<n)
		{
			if(sum-a[p]>=y)
			{
				puts("0");
				continue;
			}
		}
		p--;
		if(p>=0)
		{
			ans=min(ans,x-a[p]+max((ll)0,y-(sum-a[p])));
		}
		p=upper_bound(a,a+n,sum-y)-a;
		if(p<n)
		{
			ans=min(ans,y-(sum-a[p])+max((ll)0,x-a[p]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}