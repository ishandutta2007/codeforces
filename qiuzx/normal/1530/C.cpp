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
#define N 100010
using namespace std;
ll n,a[N],b[N],sum[N],sum2[N];
bool check(ll x)//assume that you get another x 100 and he gets another x 0
{
	ll del=(x+n)/4,chs,pts1,pts2;
	chs=x+n-del;
	if(del>=n)
	{
		pts1=100*chs;
	}
	else
	{
		pts1=100*x+sum[n]-sum[del];
	}
	pts2=sum2[min(n,chs)];
	if(pts1>=pts2)
	{
		return true;
	}
	return false;
}
int main(){
	ll T,i,l,r,mid;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		reverse(b,b+n);
		sum[0]=sum2[0]=0;
		for(i=0;i<n;i++)
		{
			sum[i+1]=sum[i]+a[i];
			sum2[i+1]=sum2[i]+b[i];
		}
		l=0;
		r=INF;
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