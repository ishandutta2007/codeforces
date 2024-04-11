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
#define N 200010
using namespace std;
ll n,m,a[N],b[N],len[N],slen[N],len2[N],idx,idy;
ll calc(ll x,ll y)
{
	ll ret=0;
	if(x&&y)
	{
		if(len2[y]<=x)
		{
			ret+=len2[y]*y+slen[x]-slen[len2[y]];
		}
		else
		{
			ret+=x*y;
		}
	}
	if(x<n&&y<m)
	{
		if(len2[y]<=x)
		{
			ret+=(n-x)*(m-y);
		}
		else
		{
			ret+=(n-len2[y])*(m-y)+m*(len2[y]-x)-slen[len2[y]]+slen[x];
		}
	}
	return ret;
}
bool check(ll v)
{
	ll i,j;
	len[0]=m;
	for(i=1;i<=n;i++)
	{
		for(len[i]=len[i-1];len[i]>0;len[i]--)
		{
			if(a[i]+b[len[i]]<=v)
			{
				break;
			}
		}
		slen[i]=slen[i-1]+len[i];
	}
	len2[0]=n;
	for(i=1;i<=m;i++)
	{
		for(len2[i]=len2[i-1];len2[i]>0;len2[i]--)
		{
			if(a[len2[i]]+b[i]<=v)
			{
				break;
			}
		}
	}
	ll ans=0,ans2=0;
	for(i=0,j=0;i<=n;i++)
	{
		for(;j<m;j++)
		{
			if(calc(i,j)>calc(i,j+1))
			{
				break;
			}
		}
		ans=max(ans,calc(i,j));
	}
	for(i=0,j=0;i<=n;i++)
	{
		for(;j<m;j++)
		{
			if(calc(i,j)-(idx>i&&idy>j)>calc(i,j+1)-(idx>i&&idy>j))
			{
				break;
			}
		}
		ans2=max(ans2,calc(i,j)-(idx>i&&idy>j));
	}
	return (ans!=ans2+1);
}
int main(){
	ll i;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
	}
	ll x=a[1],y=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	idx=lower_bound(a+1,a+n+1,x)-a;
	idy=lower_bound(b+1,b+m+1,y)-b;
	ll l=0,r=x+y;
	while(l<r)
	{
		ll mid=(l+r)>>1;
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
	return 0;
}