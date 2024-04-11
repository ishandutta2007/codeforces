#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define N 200010
using namespace std;
ll n,m,fa[N],conn=0;
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%mod;
	if(y&1)
	{
		return (ret*x)%mod;
	}
	return ret;
}
ll getf(ll x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
int main(){
	ll i,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<2*n;i++)
	{
		fa[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--,y--;
		if(z==0)
		{
			//x,y+n x+n,y
			fa[getf(x)]=getf(y+n);
			fa[getf(y)]=getf(x+n);
		}
		else
		{
			//x,y x+n,y+n
			fa[getf(x)]=getf(y);
			fa[getf(x+n)]=getf(y+n);
		}
	}
	for(i=0;i<n;i++)
	{
		if(getf(i)==getf(i+n))
		{
			puts("0");
			return 0;
		}
	}
	for(i=0;i<2*n;i++)
	{
		if(getf(i)==i)
		{
			conn++;
		}
	}
	printf("%lld\n",ksm(2,(conn/2)-1));
	return 0;
}