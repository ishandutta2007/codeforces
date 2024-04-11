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
#define N 200010
using namespace std;
ll n,k,h[N];
bool mis(ll a,ll b,ll x,ll y)
{
	if(b<x||a>y)
	{
		return true;
	}
	return false;
}
int main(){
	ll t,i,l,r;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
		}
		l=h[0];
		r=h[0];
		for(i=0;i+1<n;i++)
		{
			if(mis(h[i],h[i]+k-1,l,r))
			{
				i=-1;
				break;
			}
			l-=(k-1);
			r+=(k-1);
			l=max(l,h[i+1]);
			r=min(r,h[i+1]+k-1);
		}
		if(i==-1||mis(h[n-1],h[n-1],l,r))
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}