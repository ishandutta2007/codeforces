/*
:
1. DFS
2.(0->1)(1->0)
3.in[x]out[x]LazyTag() 
4.in[x],
5. 
*/
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 500010
using namespace std;
struct SegT{
	ll l,r,val1,val2;//NOTE: Without LazyTag
}segt[4*N];
ll n,q,din[N],dout[N],cnt=0;
vector<ll> vt[N];
void dfs(ll x,ll lst)
{
	din[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
		}
	}
	dout[x]=cnt;
	return;
}
void build_tree(ll l,ll r,ll x)
{
	segt[x].l=l;
	segt[x].r=r;
	segt[x].val1=0;
	segt[x].val2=0;
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1,a=(x<<1);
	build_tree(l,mid,a);
	build_tree(mid+1,r,a+1);
	return;
}
void upd(ll l,ll r,ll x,ll val)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		segt[x].val1=val;
		return;
	}
	ll mid=(tl+tr)>>1,a=(x<<1);
	if(mid>=l)
	{
		upd(l,r,a,val);
	}
	if(mid<r)
	{
		upd(l,r,a+1,val);
	}
	return;
}
void upd2(ll l,ll x,ll val)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>l||tr<l)
	{
		return;
	}
	if(l==tl&&tr==l)
	{
		segt[x].val2=val;
		return;
	}
	ll mid=(tl+tr)>>1,a=(x<<1);
	if(mid>=l)
	{
		upd2(l,a,val);
	}
	else
	{
		upd2(l,a+1,val);
	}
	segt[x].val2=max(segt[a].val2,segt[a+1].val2);
	return;
}
ll ga(ll l,ll x)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>l||tr<l)
	{
		return 0;
	}
	if(tl==l&&tr==l)
	{
		return segt[x].val1;
	}
	ll ret=segt[x].val1,mid=(tl+tr)>>1,a=(x<<1);
	if(mid>=l)
	{
		ret=max(ret,ga(l,a));
	}
	else
	{
		ret=max(ret,ga(l,a+1));
	}
	return ret;
}
ll ga2(ll l,ll r,ll x)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return 0;
	}
	if(tl>=l&&tr<=r)
	{
		return segt[x].val2;
	}
	ll ret=0,mid=(tl+tr)>>1,a=(x<<1);
	if(mid>=l)
	{
		ret=max(ret,ga2(l,r,a));
	}
	if(mid<r)
	{
		ret=max(ret,ga2(l,r,a+1));
	}
	return ret;
}
ll getans(ll x)
{
	ll a=ga(din[x],1),b=ga2(din[x],dout[x],1);
	if(a>b)
	{
		return 1;
	}
	return 0;
}
int main(){
	ll i,x,y;
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	build_tree(1,cnt,1);
	scanf("%lld",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		y--;
		if(x==1)
		{
			upd(din[y],dout[y],1,i);
		}
		else if(x==2)
		{
			upd2(din[y],1,i);
		}
		else
		{
			printf("%lld\n",getans(y));
		}
	}
	return 0;
}