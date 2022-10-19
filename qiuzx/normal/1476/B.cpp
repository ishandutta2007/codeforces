#pragma GCC optimize(2)
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
#define N 110
using namespace std;
ll n,k,p[N];
bool check(ll x)
{
	ll sum=p[0]+x,i;
	for(i=1;i<n;i++)
	{
		if(100*p[i]>k*sum)
		{
			return false;
		}
		sum+=p[i];
	}
	return true;
}
int main(){
	ll t,i,l,r,mid;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&p[i]);
		}
		l=0;
		r=1000000000000;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%lld\n",l);
	}
	return 0;
}